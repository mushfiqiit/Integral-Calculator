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
}
