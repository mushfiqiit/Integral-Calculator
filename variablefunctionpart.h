#ifndef VARIABLEFUNCTIONPART_H
#define VARIABLEFUNCTIONPART_H
#include <bits/stdc++.h>
#include "coefficientpart.h"

using namespace std;

class variableFunctionPart
{
    string variableFunctionAsInput;
    string outputVariableFunction;
    int functionType;
    string coefficientStringAsInput;
    Coefficientpart coefficient_Part_1;

    // All the type wise calculations
        void computeOutputVariableFunctionForFunctionTypeOne();
        void computeOutputVariableFunctionForFunctionTypeTwo();
        void computeOutputVariableFunctionForFunctionTypeThree();
        void computeOutputVariableFunctionForFunctionTypeFour();
        void computeOutputVariableFunctionForFunctionTypeFive();
        void computeOutputVariableFunctionForFunctionTypeSix();
        void computeOutputVariableFunctionForFunctionTypeSeven();
        void computeOutputVariableFunctionForFunctionTypeEight();
        void computeOutputVariableFunctionForFunctionTypeNine();

    public:
        variableFunctionPart(); // (1)
        void setVariableFunctionAsInput(string variableFunctionAsInput); // (2)
        string getVariableFunctionAsInput(); // (3)
        bool functionIsX(); //(4)
        bool functionIsEmpty(); //(5)
        void setFunctionType(int functionTypeCode); // (6) // Set function type from term class
        string getOutputVariableFunction(); // (7)
        void formOutputVariableFunction(); // (8) Called by term class to start calculation
        string getCoefficientStringAsInput(); // (9)


        int getCoefficientFractionStatus(); // (10)
        string getCoefficientNumerator(); // (11)
        string getCoefficientDenominator(); // (12)
};

#endif // VARIABLEFUNCTIONPART_H
