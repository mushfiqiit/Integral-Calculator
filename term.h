#ifndef TERM_H
#define TERM_H
#include <bits/stdc++.h>

using namespace std;

// A term class that contains a whole term where characters will be categorized.

class term
{
    string recievedTerm;
    string processedTerm;
    public:
        term();
        setTerm(string seperatedTerm)
        {
            this.seperatedTerm=seperatedTerm;
        }
};

#endif // TERM_H
