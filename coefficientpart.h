#ifndef COEFFICIENTPART_H
#define COEFFICIENTPART_H
#include <bits/stdc++.h>
#include "helpingtools.h"

using namespace std;

class Coefficientpart
{
    string coefficentAsInput;
    string outputCoefficient;
    int cofficientAsInt;
    int fractionStatus;
    helpingtools helping_Tools_1;

    string coefficientNumerator;
    string coefficientDenominator;

    public:
        Coefficientpart();
        void setCoeffficientAsInput(string coefficentAsInput);
        string getCoefficientAsInput();
        void setFractionStatus(int fractionStatus);
        int getFractionStatus();
        string getCoefficientNumerator();
        string getCoefficientDenominator();
        string getCoefficient();
        void formOutputCoefficient();
};

#endif // COEFFICIENTPART_H
