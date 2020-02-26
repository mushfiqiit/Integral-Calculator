#ifndef TERM_H
#define TERM_H
#include <bits/stdc++.h>
#include "constantpart.h"
#include "variablefunctionpart.h"
#include "powerpart.h"

using namespace std;

// A term class that contains a whole term where characters will be categorized.

class term
{
    string recievedTerm;
    string outputTerm;
    constantPart constant_Part_1;
    variableFunctionPart variable_Function_Part_1;
    powerPart power_Part_1;

        void termProcessor();
        void computeOutputTerm();
    public:
        term();
        void setTerm(string seperatedTerm);
        string getInitialTerm();
        string getProcessedTerm();
        constantPart getConstantPart();
        variableFunctionPart getVariableFunctionPart();
        powerPart getPowerPart();
        void formOutputTerm();
        string getOutputTerm();
};
#endif // TERM_H
