#ifndef VARIABLEFUNCTIONPART_H
#define VARIABLEFUNCTIONPART_H
#include <bits/stdc++.h>

using namespace std;

class variableFunctionPart
{
    string variableFunctionAsInput;
    string outputVariableFunction;
    int functionType;
    string coefficientAsString;
    Coefficientpart coefficient_Part_1;

        void computeOutputVariableFunctionForFunctionTypeOne();
        /*
        For type one, the variable function will stay as it is in the input.
        */

        void computeOutputVariableFunctionForFunctionTypeTwo();
        /*
        The output variableFunction will be lnx.
        */

    public:
        variableFunctionPart();
        void setVariableFunctionAsInput(string variableFunctionAsInput);
        void formOutputVariableFunction();
        /*
        Recieves a signal from term class to form the output variableFunction.
        */
        string getVariableFunctionAsInput();
        bool functionIsX();
        bool functionIsEmpty();
        void setFunctionType(int functionTypeCode);
        /*
        A method for knowing what the function type is.
        */
        string getOutputVariableFunction();
};

#endif // VARIABLEFUNCTIONPART_H
