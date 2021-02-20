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
    int functionType;

        void termProcessor();

        void computeOutputTerm();

        void identifyFunctionType(string constant, string variableFunction, string power);

        void setTermFunctionType(int functionTypeCode);

    public:
        term();
        void setTerm(string seperatedTerm); //Recieve a term from input taking unit.
        string getInitialTerm();
        string getProcessedTerm();
        constantPart getConstantPart();
        variableFunctionPart getVariableFunctionPart();
        powerPart getPowerPart();
        void formOutputTerm(); // Called by input taking unit to start the processing.
        string getOutputTerm(); // Returns output term to input taking unit.
};
#endif // TERM_H
