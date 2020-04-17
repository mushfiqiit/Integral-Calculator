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
        /*
        A method where the input is seperated to parts
        */

        void computeOutputTerm();
        /*
        The output of seperated parts are combined to form final result.
        */

        void identifyFunctionType(string constant, string variableFunction, string power);
        /*
        The type of function is identified and marked with a code.
        All the other parts are marked accordingly.
        Code 1: The function is a regualar polynomial.
        Code 2: The function has power -1 which will give us a lnx output.
        */

        void setTermFunctionType(int functionTypeCode);
        /*
        After the function has been identified, it's time to set the functionType
        with a code number for the term and also it's seperated parts.
        */

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
