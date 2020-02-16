#ifndef POWERPART_H
#define POWERPART_H
#include <bits/stdc++.h>

using namespace std;

class powerPart
{
    string inputPower;
    string OutPutPower;

    int convertedInputPower;
    int convertedOutputPower;
    public:
        powerPart();
        void setInputPower(string inputPower);
        string getInputPower();
};

#endif // POWERPART_H
