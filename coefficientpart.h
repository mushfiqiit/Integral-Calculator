#ifndef COEFFICIENTPART_H
#define COEFFICIENTPART_H
#include <bits/stdc++.h>

using namespace std;

class Coefficientpart
{
    string coefficentAsInput;
    int cofficientAsInt;
    int fractionStatus;

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
};

#endif // COEFFICIENTPART_H
