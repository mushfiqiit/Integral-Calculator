#ifndef POWERPART_H
#define POWERPART_H
#include <bits/stdc++.h>

using namespace std;

class powerPart
{
    string inputPower;
    string outputPower;
    int convertedInputPower;
    int convertedOutputPower;

    void computeOutputPower();
    public:
        powerPart();
        void setInputPower(string inputPower);
        string getInputPower();
        void formOutputPower();
        string getOutputPower();
};

#endif // POWERPART_H
