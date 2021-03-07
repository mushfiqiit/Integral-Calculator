#ifndef TERM_H
#define TERM_H
#include <bits/stdc++.h>
#include "constantpart.h"
#include "variablefunctionpart.h"
#include "powerpart.h"
#include "variableFunctionPartTypeB.h"

using namespace std;

// A term class that contains a whole term where characters will be categorized.

class term
{
    string recievedTerm;
    string outputTerm;
    constantPart constant_Part_1;
    variableFunctionPart variable_Function_Part_1;
    powerPart power_Part_1;
    variableFunctionPartTypeB variable_Function_Part_TypeB_1;
    int functionType;

        void termProcessorForTypeA(); // 9

        void termProcessorForTypeB(); // 10

        void computeOutputTermForTypeA(); // 11

        void computeOutputTermForTypeB();

        void identifyFunctionType(string constant, string variableFunction, string power); // 12

        void setTermFunctionType(int functionTypeCode); // 13

    public:
        term(); // 1
        void setTerm(string seperatedTerm); // 2 -Recieve a term from input taking unit.
        string getInitialTerm(); // 3
        //string getProcessedTerm();
        constantPart getConstantPart(); // 4
        variableFunctionPart getVariableFunctionPart(); // 5
        powerPart getPowerPart(); // 6
        void formOutputTerm(); // 7 - Called by input taking unit to start the processing.
        string getOutputTerm(); // 8 - Returns output term to input taking unit.
};
#endif // TERM_H
