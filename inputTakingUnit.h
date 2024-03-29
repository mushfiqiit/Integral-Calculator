#ifndef INPUTTAKINGUNIT_H
#define INPUTTAKINGUNIT_H
#include <bits/stdc++.h>
#include "term.h"
#include "outputUnit.h"

using namespace std;


class inputTakingUnit
{
    vector <char> operatorSigns;
    string recievedInput;
    string processedToTerm;
    term arrayOfTerms[5];
    string arrayOfTermStrings[5];
    outputUnit outputUnit_1;

    void formOutputString(int termCount);
    void processInputToTerms();
    public:
        inputTakingUnit();
        bool takeInput();
        string getProcessedTerm();
        string getRecievedInput();
};

#endif // INPUTTAKINGUNIT_H
