#include "variablefunctionpart.h"
#include <bits/stdc++.h>

using namespace std;

variableFunctionPart::variableFunctionPart()
{

}

void variableFunctionPart::setVariableFunctionAsInput(string variableFunctionAsInput)
{
    this->variableFunctionAsInput=variableFunctionAsInput;
}

string variableFunctionPart::getVariableFunctionAsInput()
{
    return variableFunctionAsInput;
}

bool variableFunctionPart::functionIsX()
{
    if(variableFunctionAsInput=="x")
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool variableFunctionPart::functionIsEmpty()
{
    if(variableFunctionAsInput.empty())
    {
        return true;
    }

    else
    {
        return false;
    }
}

void variableFunctionPart::setFunctionType(int functionTypeCode)
{
    this->functionType=functionTypeCode;
    //cout << functionType << " " << functionTypeCode << endl;
}

void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeTwo()
{
    outputVariableFunction="ln" + variableFunctionAsInput;
}

void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeOne()
{
    outputVariableFunction=variableFunctionAsInput;
}

string variableFunctionPart::getOutputVariableFunction()
{
    return this->outputVariableFunction;
}

void variableFunctionPart::formOutputVariableFunction()
{
    //cout << functionType << endl;
    if(functionType==1)
    {
        computeOutputVariableFunctionForFunctionTypeOne();
    }

    else if(functionType==2)
    {
        computeOutputVariableFunctionForFunctionTypeTwo();
    }
}
