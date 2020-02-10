#ifndef INPUTTAKINGUNIT_H
#define INPUTTAKINGUNIT_H
#include <bits/stdc++.h>
#include "term.h"

using namespace std;


class inputTakingUnit
{
    string recievedInput;
    string processedToTerm;

    void processInputToTerms();
    public:
        inputTakingUnit();
        void takeInput();
        string getProcessedTerm();
        string getRecievedInput();

};

#endif // INPUTTAKINGUNIT_H
