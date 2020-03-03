#ifndef CONSTANTPART_H
#define CONSTANTPART_H
#include <bits/stdc++.h>

using namespace std;

class constantPart
{
    string constantStringAsInput;
    string outputConstant;

    string initialNumerator;
    string initialDenominator;

    string processedNumerator;
    string processedDenominator;
    int fractionStatus;

    void computeOutputConstant(string inputPower);
    void numeratorDenominatorSimplification(string numerator, string denominator);
    void computeFractionNumeratorDenominator(string constantStringAsInput,
                                             string inputPower);
    public:
        constantPart();
        void setConstant(string constantStringAsInput);
        string getConstantStringAsInput();
        void formOutputConstant(string inputPower);
        string getOutputConstant();
        void setFractionStatus(int fractionStatus);
        int getFractionStatus();
};

#endif // CONSTANTPART_H
