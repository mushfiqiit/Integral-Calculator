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
    string outputPowerNumerator;
    string outputPowerDenominator;
    int fractionStatus;
    bool isPositive;
    int functionType;

    void computeOutputConstant();
    void numeratorDenominatorSimplification(string numerator, string denominator);
    void computeFractionNumeratorDenominator(string initialNumerator,
                                             string initialDenominator);
    void parseFractionConstant(string constantStringAsInput);
    public:
        constantPart();
        void setConstant(string constantStringAsInput);
        string getConstantStringAsInput();
        void formOutputConstant();
        string getOutputConstant();
        void setFractionStatus(int fractionStatus);
        int getFractionStatus();
        void setOutputPowerNumerator(string outputPowerNumerator);
        void setOutputPowerDenominator(string outputPowerDenominator);
        void setFunctionType(int functionTypeCode);
};

#endif // CONSTANTPART_H
