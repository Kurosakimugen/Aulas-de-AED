#include "funHashingProblem.h"

FunHashingProblem::FunHashingProblem() {}


//=============================================================================
// Exercise 1: Find Duplicates
//=============================================================================
// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_set<int> testerep;
    for (int i : values) {
        if (testerep.find(i) != testerep.end() ) {
            res.push_back(i);
        }
        else {
            if (testerep.size() < k) {
                testerep.insert(i);
                continue;
            }
            if (testerep.size() == k) {
                auto l = testerep.begin();
                testerep.erase(l);
                testerep.insert(i);
                continue;
            }
        }
    }
    return res;
}
