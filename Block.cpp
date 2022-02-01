//
// Created by manjaro on 28.01.22.
//


#include "Block.h"
#include "snipper/Snipper.h"
#include "NaiveBayes.h"

/** Create from a Database a k-Fold Modell with random added patients from your database
 *
 * @S          Your SNP-Database
 * @count      Count of k
 * @return     k-fold model with random added patients from your SNP-Database
 * */
Block::K_Fold Block::Splitter(Snipper &S, int count) {

    // Create k empty blocks ( k = count )

        K_Fold k_Blocks;

        for (int i = 0 ; i < count ; i++) {
            Block K(S,i);
            k_Blocks.push_back(K);
        }

    // Extract the patient_ids from the given Snipper ( rows )

        int patientcount = S.getClassifics().count();
        std::vector<int> patients;
        patients.reserve(patientcount);
        for (int i = 0 ; i < patientcount ; i++ ) { patients.push_back(i); }

    // Shuffle the Patient-id-List for random blocks

        auto rd = std::random_device();
        auto rng = std::default_random_engine(rd());
        std::shuffle(std::begin(patients),std::end(patients),rng);

    // Add Patients to all Blocks

        int _block = 0;
        int added  = 0;
        int block_size = patientcount / count;

        for (int id : patients) {

            k_Blocks[_block].addPatient(id);

            if (added >= block_size-1) {  _block++;
                                          added = 0;
                                } else {  added++;
            }
        }

    // Return finished k-Fold Structure

    return k_Blocks;
}



/** Tests this Patient-Data in this Block and returns the Statistics
 *
 * @NB
 * @
 * @result        Statistics of this Testing
 * */
void Block::calcStatistics(NaiveBayes& NB) {


    // Count True and Predict Classifications

    int count              = 0;
    int TruePositives      = 0;
    int TrueNegatives      = 0;
    int FalsePositives     = 0;
    int FalseNegatives     = 0;

    for (int pat_id : this->patient) {

        Classification TrueState    = this->S.getClassifics()[pat_id];
        Classification PredictState = this->predictions[count];

        TrueState == Cancer  && PredictState == Cancer  ? TruePositives++  : TruePositives;
        TrueState == Cancer  && PredictState == Control ? FalsePositives++ : FalsePositives;
        TrueState == Control && PredictState == Cancer  ? FalseNegatives++ : FalseNegatives;
        TrueState == Control && PredictState == Control ? TrueNegatives++  : TrueNegatives;

        count++;

    }

    // int to double cast

    double TP = TruePositives;
    double FP = FalsePositives;
    double TN = TrueNegatives;
    double FN = FalseNegatives;

    // compute St

    double ac = Statistics::Accuracy( TP,  TN,  FP,  FN);
    double se = Statistics::Sensitivity( TN,  FP);
    double sp = Statistics::Specificity( TP,  FN);
    double pr = Statistics::Precision( TP,  FP);
    double f1 = Statistics::F1Score( pr,  se);

    //

    double av = 80;//Average(std::vector<double> list);
    double dv = 15;//Standard_deviation(std::vector<double> Xi,std::vector<double> pXi);

    // Store Statistics of this Testing

    NB.getStats().addStatsSet(ac,se,sp,pr,f1,av,dv);

}




/** returns for patient X (patient_id) the log odd ratio of Cancer / Control
 *
 * @patient_id     Patient to predict the classification
 * @return         Type of Classification
 * */
void Block::predict(Model& M, Snipper& S) {

    double pC = M.getPCancer();
    double pN = M.getPControl();
    int pred_pos = 0;

    // Run over all patients in this block
    for (int id : this->getBlockPatients()) {
        // start prob's
        double pXiC = 1;
        double pXiN = 1;

        // run over all SNP's
        for (int Xi = 0 ; Xi < S->getSNPcount() ; Xi++ ) {
            Genotype gen = S[Xi][id];
            pXiC *= M.getGenProbAtXi(Cancer,gen,Xi);
            pXiN *= M.getGenProbAtXi(Control,gen,Xi);
        }

        // compute the prediction and add this to this block
        this->predictions[pred_pos] = NaiveBayes::LOR_Formula( pXiC,  pXiN,  pC,  pN);
        pred_pos++;
        //
    }
}


/** Print this Data-Block to console
 *
 * */
void Block::print() {
    std::stringstream s("");
    s << C::BWHITE <<"\n K-Block id:"<<kid<<" size: "<< C::BBLUE << patient.size()  << C::BRED << " [ *SNPs: " << S.getSNPcount() << " Pat: " << S.getClassifics().count() << " ]";
    s << C::BWHITE << " Pat(pred): { ";
    int idx = 0;
    for (int pat : patient ) {
        s << C::BBLUE << pat << C::BCYAN << " (" << predictions[idx] << ") ";
        if (idx != (int)patient.size() - 1) {s << "; ";}
        idx++; }
    s << C::BWHITE << "} ";
    std::cout << s.str() << C::RESET;
}



/** Constructor of a Block
 *
 * @S   Your SNP-Database
 * */
Block::Block(Snipper &S, int id) {
    this->S = S;
    this->kid = id;
}

