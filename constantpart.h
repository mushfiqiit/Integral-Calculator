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

    void computeOutputConstant(string inputPower);
    public:
        constantPart();
        void setConstant(string constantStringAsInput);
        string getConstantStringAsInput();
        void formOutputConstant(string inputPower);
        string getOutputConstant();
};

#endif // CONSTANTPART_H
