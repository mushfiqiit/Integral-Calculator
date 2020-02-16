#ifndef CONSTANTPART_H
#define CONSTANTPART_H
#include <bits/stdc++.h>

using namespace std;

class constantPart
{
    string constantStringAsInput;
    string outputConstant;

    int processedConstant;
    int constantIntegerAsInput;

    public:
        constantPart();
        void setConstant(string constantStringAsInput);
        string getConstantStringAsInput();
};

#endif // CONSTANTPART_H
