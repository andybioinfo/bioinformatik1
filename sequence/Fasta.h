#ifndef BIOINFOI_FASTA_H
#define BIOINFOI_FASTA_H

#include "Sequence.h"
#include "ParsingException.h"

#include <istream>
#include <ostream>

/**
 * A simple helper class used to signal
 * that we want to write a DNA sequence in 2Bit format.
 */
template<typename Alpha>
class SequenceFastaWriter
{
  public:
	SequenceFastaWriter(const Sequence<Alpha>& seq);

	/// Global input operator
	template<typename A>
	friend std::ostream& operator<<(std::ostream& strm,
	                                const SequenceFastaWriter<A>&);

  private:
	/// Stores a reference to the sequence to write.
	const Sequence<Alpha>& seq_;
};

/**
 * A simple helper class used to signal
 * that we want to read a DNA sequence in 2Bit format.
 */
template<typename Alpha>
class SequenceFastaReader
{
  public:
	SequenceFastaReader(Sequence<Alpha>& seq);

	/// Global input operator (Needs an rvalue reference to work with from2Bit...)
	template<typename A>
	friend std::istream& operator>>(std::istream& strm, SequenceFastaReader<A>&&);

  private:
	/// Stores a reference to the sequence to read.
	Sequence<Alpha>& seq_;
};

template<typename Alpha>
SequenceFastaWriter<Alpha> toFasta(const Sequence<Alpha>& seq) {
	return SequenceFastaWriter<Alpha>(seq);
}

template<typename Alpha>
SequenceFastaReader<Alpha> fromFasta(Sequence<Alpha>& seq) {
	return SequenceFastaReader<Alpha>(seq);
}

template <typename Alpha>
SequenceFastaReader<Alpha>::SequenceFastaReader(Sequence<Alpha>& seq)
    : seq_(seq)
{
}

template <typename Alpha>
std::ostream& operator<<(std::ostream& strm,
                         const SequenceFastaWriter<Alpha>& writer)
{
	strm << '>' << writer.seq_.getComment() << '\n';

	const size_t line_width = 79;

	for (size_t offset = 0; offset < writer.seq_.size(); offset += line_width) {
		auto from = writer.seq_.cbegin() + offset;
		auto to = (offset + line_width >= writer.seq_.size())
		              ? writer.seq_.cend()
		              : (from + line_width);

		std::transform(from, to, std::ostream_iterator<char>(strm),
		               Alpha::toChar);
		strm << '\n';
	}

	return strm;
}

template <typename Alpha>
std::istream& operator>>(std::istream& strm,
                         SequenceFastaReader<Alpha>&& reader)
{
	char start = strm.get();

	if(start != '>') {
		throw ParsingException(std::string("Expected '>' but got '") + start +
		                       "'.");
	}

	reader.seq_.clear();

	std::string line;
	std::getline(strm, line);

	reader.seq_.setComment(line);

	while(strm.peek() != '>' && strm.good()) {
		std::getline(strm, line);

		for(auto c : line) {
			reader.seq_.push_back(Alpha::toCharacter(c));
		}
	}

	return strm;
}

template <typename Alpha>
SequenceFastaWriter<Alpha>::SequenceFastaWriter(const Sequence<Alpha>& seq)
    : seq_(seq)
{
}

#endif // BIOINFOI_FASTA_H

