#ifndef POWERPART_H
#define POWERPART_H
#include <bits/stdc++.h>

using namespace std;

class powerPart
{
    string inputPower;
    string outputPower;

    string numerator;
    string denominator;

    string numeratorAsOutput;
    string denominatorAsOutput;

    string processedNumerator;
    string processedDenominator;

    int convertedInputPower;
    int convertedOutputPower;
    bool isPositive;
    int fractionStatus;

    void computeOutputPower();
    void computeFractionalPowerAsOutput(string numerator, string denominator);
    void numeratorDenominatorSimplification(string numerator, string denominator);
    public:
        powerPart();
        void setInputPower(string inputPower);
        string getInputPower();
        void formOutputPower();
        string getOutputPower();
        void setFractionStatus(int fractionStatus);
        int getFractionStatus();
        string getNumerator();
        string getDenominator();
        string getNumeratorAsOutput();
        string getDenominatorAsOutput();
};

#endif // POWERPART_H
