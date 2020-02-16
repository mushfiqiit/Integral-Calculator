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
    string processedTerm;
    constantPart constant_Part_1;
    variableFunctionPart variable_Function_Part_1;
    powerPart power_Part_1;

        void termProcessor();
    public:
        term();
        void setTerm(string seperatedTerm);
        string getInitialTerm();
        string getProcessedTerm();
        constantPart getConstantPart();
};

#endif // TERM_H
