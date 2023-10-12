#include "funListStackQueueProblem.h"
#include "cell.h"

FunListStackQueueProblem::FunListStackQueueProblem() {}


//=============================================================================
// Exercise 1: Remove Higher
//=============================================================================
// TODO
list<int> FunListStackQueueProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    auto iter = values.begin();
    while (iter != values.end()) {
        if (*iter > x) {
            l1.push_back(*iter);
            iter = values.erase(iter);
        }
        else {
            iter++;
        }
    }
    return l1;
}



//=============================================================================
// Exercise 2: Overlapping Intervals
//=============================================================================
//TODO
list<pair<int,int>> FunListStackQueueProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int,int>> res;
    return res;
}


//=============================================================================
// Exercise 4: Binary Numbers
//=============================================================================
// TODO
vector<string> FunListStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    for (int i = 1 ; i <= n; i++) {
        if (i != 1) {
            if (i % 2 != 0) {
                i = i - 1;
            }
            if (i)
        }
        else{
            res.push_back("1");
        }
    }
    return res;
}


//=============================================================================
// Exercise 5: Calculate Span
//=============================================================================
//TODO
vector<int> FunListStackQueueProblem::calculateSpan(vector<int> prices) {
    vector<int> res;
    return res;
}


//=============================================================================
// Exercise 7: Knight Jumps
//=============================================================================
//TODO
int FunListStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}
