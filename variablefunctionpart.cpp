#include "variablefunctionpart.h"
#include <bits/stdc++.h>

using namespace std;

variableFunctionPart::variableFunctionPart()
{

}

void variableFunctionPart::setVariableFunctionAsInput(string variableFunctionAsInput)
{
    this->variableFunctionAsInput=variableFunctionAsInput;

    if(functionType==3)
    {
        for(int i=0;i<variableFunctionAsInput.length();i++)
        {
            if(variableFunctionAsInput[i]=='/')
            {
                coefficient_Part_1.setFractionStatus(1);
            }

            //cout << variableFunctionAsInput[i] << endl;
            if((variableFunctionAsInput[i]>='0' && variableFunctionAsInput[i]<='9')
               || variableFunctionAsInput[i]=='(' || variableFunctionAsInput[i]==')'
               || variableFunctionAsInput[i]=='/')
            {
                coefficientStringAsInput=coefficientStringAsInput+variableFunctionAsInput[i];
            }
        }
        //cout << coefficientStringAsInput << endl;
        coefficient_Part_1.setCoeffficientAsInput(coefficientStringAsInput);
    }
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

string variableFunctionPart::getCoefficientStringAsInput()
{
    this->coefficientStringAsInput=coefficient_Part_1.getCoefficientAsInput();
    return this->coefficientStringAsInput;
}

int variableFunctionPart::getCoefficientFractionStatus()
{
    return this->coefficient_Part_1.getFractionStatus();
}

string variableFunctionPart::getCoefficientNumerator()
{
    return this->coefficient_Part_1.getCoefficientNumerator();
}

string variableFunctionPart::getCoefficientDenominator()
{
    return this->coefficient_Part_1.getCoefficientDenominator();
}
