#ifndef TERM_H
#define TERM_H
#include <bits/stdc++.h>
#include "constantpart.h"

using namespace std;

// A term class that contains a whole term where characters will be categorized.

class term
{
    string recievedTerm;
    string processedTerm;
    constantPart constant_1;

        void termProcessor();
    public:
        term();
        void setTerm(string seperatedTerm);
        string getInitialTerm();
        string getProcessedTerm();
};

#endif // TERM_H
