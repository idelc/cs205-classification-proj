#ifndef SRCH_ALGO_H
#define SRCH_ALGO_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

double defaultRate(double data_array[], unsigned& rows, unsigned& cols){
    unsigned cnt1=0, cnt2;
    for(unsigned i = 0; i < rows; i++){
//        cout << "i is: " << i << endl;
        if(static_cast<int>(data_array[cols*i]) == 1){
            // cout << data[i][0] << " is a 1" << endl;
            cnt1++;
        }
    }
    cnt2 = rows - cnt1;
    return (cnt1 > cnt2) ? cnt1/static_cast<double>(rows) : cnt2/static_cast<double>(rows);
}

bool isInFeatVec(int nFeat, vector<unsigned> oFeat){
    for(unsigned i = 0; i < oFeat.size(); i++){
        if(oFeat[i] == nFeat){
            return true;
        }
    }
    return false;
}


double kValidation_dummy(vector<unsigned>feat, double data[], unsigned& r, unsigned& c){
    return (rand()%99)/100.0;
}

// TODO: add extra features for big data set
void forwardSelection(double data[], unsigned& rows, unsigned& cols){
    double bestSoFar = defaultRate(data, rows, cols); // find: largest class/ total items
    double val = 0.0;
    int fToAdd = -1;
    double BestLevel = 0.0;
    bool duplicate;

    vector<unsigned> features; // current best set of feat
    vector<double> accuVec; // track accuracy history

    cout << "Default rate is: " << bestSoFar << endl << endl;

    for(unsigned i = 1; i < cols; i++){ // search through each feature
        fToAdd = -1;
        BestLevel = 0.0;
        cout << "Level " << i << ' ' << endl;
        for(unsigned j = 1; j < cols; j++){ // start from 1 because feature 0 is ID
            duplicate = isInFeatVec(j, features);
            if(!duplicate){
                // cout << "Considering feature " << j << "...\t";
                features.push_back(j);
                val = kValidation_dummy(features, data, rows, cols); // TODO: Replace when kval done
                cout.precision(5);
                // cout << "accuracy is " << val << endl;
                if(val > BestLevel){
                    BestLevel = val;
                    fToAdd = j;
                }
                if(bestSoFar < BestLevel){
                    bestSoFar = BestLevel;
                }
                features.pop_back();
            }
        }

        if(fToAdd > 0){
            cout << "On level " << i << ", added feature " << fToAdd << " with accuracy " << BestLevel << endl << endl;
            accuVec.push_back(BestLevel);
            features.push_back(fToAdd); // update final vectors
        }
        else { cout << endl;}
    }

    cout << "\nBest Features are:";
    double bestPrint = accuVec[0];
    for(unsigned n = 0; n < features.size(); n++){
        if((n > 0) && (accuVec[n] > bestPrint)){
            cout << ' ' << features[n];
            bestPrint = accuVec[n];
        }
        else if(!n){
            cout << ' ' << features[n];
        }
        // else {
        //     n = features.size() + 1;
        // }
    }
    cout << "\nBest Accuracy: " << bestPrint << endl;
}

void backwardElimination(double data[], unsigned& rows, unsigned& cols){
    double bestSoFar = 0.0;
    double val = 0.0;
    int fToCut = -1;
    double BestLevel = 0.0;
    int lvl_cnt = 0;
    vector<unsigned> features(cols-1,0);
    vector<unsigned> tempFeat;
    vector<unsigned> finalFeat;

    for(unsigned i = 0; i < cols-1; i++){
        features[i] = i;
    }

    bestSoFar = kValidation_dummy(features, data, rows, cols); // TODO: Replace when kval done

    cout << "Default rate is: " << bestSoFar << endl << endl;

    while(!features.empty() && (lvl_cnt < cols)){
        lvl_cnt++;
        fToCut = -1;
        BestLevel = 0.0;
        cout << "Level " << lvl_cnt << ' ' << endl;
        for(unsigned j = 0; j < features.size(); j++){
            tempFeat = features;
            tempFeat.erase(tempFeat.begin()+j);
            val = kValidation_dummy(features, data, rows, cols); // TODO: Replace when kval done
            cout.precision(5);
            // cout << "accuracy is " << val << endl;
//            if(fToCut == -1){
//                fToCut==
//            }
            if(val > BestLevel){
                BestLevel = val;
                fToCut = j;
            }
            if(bestSoFar < BestLevel){
                bestSoFar = BestLevel;
                //finalFeat.clear();
                finalFeat = tempFeat;
            }
        }
        if(fToCut > 0){
            cout << "On level " << lvl_cnt << ", removed feature " << features.at(fToCut) << " with new accuracy "<< BestLevel << endl << endl;

            features.erase(features.begin()+fToCut);

            // cout << "\ncurrent features are: ";
            // for(unsigned x = 0; x<features.size();x++){
            //     if(features[x]){cout << ' ' << x+1;}
            // }
            // cout << endl;

        }
        else { cout << endl;}

    }

    cout << "\nBest Features are:";
    for(unsigned n = 0; n<finalFeat.size(); n++){
        if(finalFeat[n]){
            cout << ' ' << n+1;
        }
    }
    cout << "\nBest Accuracy: " << bestSoFar << endl;

}

#endif