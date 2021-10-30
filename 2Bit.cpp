#include "2Bit.h"
#include "ParsingException.h"

#include <cassert>
#include <cstdlib>
#include <iostream>

using Seq = Sequence<Alphabet::DNA>;

Sequence2BitWriter::Sequence2BitWriter(const Seq& seq) : seq_(seq) {}

Sequence2BitReader::Sequence2BitReader(Seq& seq) : seq_(seq) {}

static uint8_t getBits(Seq::Characters c)
{
	switch (c) {
		case Seq::Characters::G:
		case Seq::Characters::g:
		case Seq::Characters::N:
			return 0b00;
		case Seq::Characters::A:
		case Seq::Characters::a:
			return 0b01;
		case Seq::Characters::T:
		case Seq::Characters::t:
			return 0b10;
		case Seq::Characters::C:
		case Seq::Characters::c:
			return 0b11;
	}

	assert("Unhandled Character in 2Bit::getBits" && false);
}

static uint8_t getMaskBits(Seq::Characters c)
{
	switch (c) {
		case Seq::Characters::A:
		case Seq::Characters::T:
		case Seq::Characters::G:
		case Seq::Characters::C:
			return 0b00;
		case Seq::Characters::a:
		case Seq::Characters::t:
		case Seq::Characters::g:
		case Seq::Characters::c:
			return 0b01;
		case Seq::Characters::N:
			return 0b10;
	}

	assert("Unhandled Character in 2Bit::getMaskBits" && false);
}

template <typename BitFunction>
static uint8_t fillByte(Seq::const_iterator first, Seq::const_iterator last,
                        const BitFunction& func)
{
	uint8_t data = 0;
	size_t i = 0;
	for (; first != last; ++first, ++i) {
		data |= func(*first) << (6 - 2 * i);
	}

	return data;
}

static Alphabet::DNA::Characters getCharacterImpl(uint8_t data, size_t i)
{
	data = data >> (2 * i) & uint8_t(0b11);
	switch (data) {
		case 0b00:
			return Seq::Characters::G;
		case 0b01:
			return Seq::Characters::A;
		case 0b10:
			return Seq::Characters::T;
		case 0b11:
			return Seq::Characters::C;
	}

	assert("Invalid byte in 2Bit::getCharacter" && false);
}

static void getCharacter(uint8_t data, Alphabet::DNA::Characters& c, size_t i)
{
	c = getCharacterImpl(data, i);
}

static Alphabet::DNA::Characters toIntron(Seq::Characters c)
{
	switch (c) {
		case Seq::Characters::G:
			return Seq::Characters::g;
		case Seq::Characters::C:
			return Seq::Characters::c;
		case Seq::Characters::A:
			return Seq::Characters::a;
		case Seq::Characters::T:
			return Seq::Characters::t;
		default:
			return c;
	}
}

static void adjustCharacter(uint8_t data, Alphabet::DNA::Characters& c,
                            size_t i)
{
	data = data >> (2 * i) & uint8_t(0b11);
	switch (data) {
		case 0b00:
			return;
		case 0b01:
			c = toIntron(c);
			return;
		case 0b10:
			c = Seq::Characters::N;
			return;
	}

	assert("Invalid byte in 2Bit::getCharacter" && false);
}

static void readHeader(std::istream& strm, Seq& seq)
{
	if (strm.get() != '>') {
		throw ParsingException("Expected '>' but got an invalid character.");
	}

	std::string name;
	std::getline(strm, name, ':');

	seq.setComment(name);

	size_t from, to;

	strm >> from;

	if (strm.get() != '-') {
		throw ParsingException("Expected '-' but got an invalid character.");
	}

	strm >> to;

	if (to < from) {
		strm.setstate(std::ios::failbit);
		return;
	}

	if (strm.get() != '\n') {
		throw ParsingException("Expected newline but got an invalid character.");
	}

	if (strm.get() != 'P') {
		throw ParsingException("Expected 'P' but got an invalid character.");
	}

	seq.resize(to - from + 1);
}

template <typename BitFunc>
static void processSingleByte(std::istream& strm, size_t from, size_t amount, Seq& seq, const BitFunc& func)
{
	if(amount == 0) {
		return;
	}

	uint8_t data = strm.get();

	if (!strm.good()) {
		throw ParsingException("Unexpected end of stream.");
	}

	for (size_t i = 0; i < amount; ++i) {
		func(data, seq[from + i], 3 - i);
	}
}

template <typename BitFunc>
static void processBits(std::istream& strm, size_t chunks, size_t rem, Seq& seq,
                        const BitFunc& func)
{
	for (size_t chunk = 0; chunk < chunks; ++chunk) {
		processSingleByte(strm, chunk * 4, 4, seq, func);
	}

	processSingleByte(strm, chunks * 4, rem, seq, func);
}

std::istream& operator>>(std::istream& strm, Sequence2BitReader&& reader)
{
	Seq& seq = reader.seq_;

	readHeader(strm, seq);

	auto chunks = seq.size() / 4;
	auto rem = seq.size() % 4;

	processBits(strm, chunks, rem, seq, getCharacter);
	processBits(strm, chunks, rem, seq, adjustCharacter);

	return strm;
}

template <typename FillFunction>
void writeSequence(std::ostream& strm, size_t chunks, const Seq& seq,
                   const FillFunction& func)
{
	for (size_t chunk = 0; chunk < chunks; ++chunk) {
		auto it = seq.begin() + 4 * chunk;
		strm.put(fillByte(it, it + 4, func));
	}

	strm.put(fillByte(seq.begin() + 4 * chunks, seq.end(), func));
}

std::ostream& operator<<(std::ostream& strm, const Sequence2BitWriter& writer)
{
	const Seq& seq = writer.seq_;

	strm << '>' << seq.getComment() << ":1-" << seq.size() << "\nP";

	auto chunks = seq.size() % 4;

	writeSequence(strm, chunks, seq, getBits);
	writeSequence(strm, chunks, seq, getMaskBits);

	return strm;
}

Sequence2BitWriter to2Bit(const Seq& sequence)
{
	return Sequence2BitWriter(sequence);
}

Sequence2BitReader from2Bit(Seq& sequence)
{
	return Sequence2BitReader(sequence);
}

