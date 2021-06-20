#ifndef CONSTANTPART_H
#define CONSTANTPART_H
#include <bits/stdc++.h>
#include "helpingtools.h"

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
    int isRootValueOfPowerNumerator, isRootValueOfPowerDenominator;
    helpingtools helping_tools_1;

    void computeOutputConstantForFunctionTypeOne();
    void computeOutputConstantForFunctionTypeTwo();
    void computeOutputConstantForFunctionTypeThree();
    void computeOutputConstantForFunctionTypeFour();
    void computeOutputConstantForFunctionTypeFive();
    void computeOutputConstantForFunctionTypeSix();
    void computeOutputConstantForFunctionTypeSeven();
    void computeOutputConstantForFunctionTypeEight();
    void computeOutputConstantForFunctionTypeNine();
    void computeOutputConstantForFunctionTypeTen();
    void computeOutputConstantForFunctionTypeTwelve();


    void numeratorDenominatorSimplification(string numerator, string denominator);
    void computeFractionNumeratorDenominator(string initialNumerator,
                                             string initialDenominator);
    void parseFractionConstant(string constantStringAsInput);
    /*
    If the constant is a fraction then we need to parse it and identify
    the numerator and denominator.
    */
    public:
        constantPart();
        void setConstant(string constantStringAsInput);
        string getConstantStringAsInput();
        void formOutputConstant(); // Called by term class
        string getOutputConstant();
        void setFractionStatus(int fractionStatus);
        int getFractionStatus();
        void setOutputPowerNumerator(string outputPowerNumerator);
        void setOutputPowerDenominator(string outputPowerDenominator);
        void setFunctionType(int functionTypeCode);
        void setIsRootValueOfPowerNumerator(int isRootValueOfPowerNumerator);
        void setIsRootValueOfPowerDenominator(int isRootValueOfPowerDenominator);
};

#endif // CONSTANTPART_H
