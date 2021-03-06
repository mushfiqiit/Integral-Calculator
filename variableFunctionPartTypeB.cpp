#include "variableFunctionPartTypeB.h"
#include <bits/stdc++.h>

using namespace std;

variableFunctionPartTypeB::variableFunctionPartTypeB() // 1
{
    //ctor
}

void variableFunctionPartTypeB::setVariableFunctionPart(string variableFunctionAsInput)
{
    this->variableFunctionAsInput=variableFunctionAsInput;
}

bool variableFunctionPartTypeB::isDigit(char ch)
{
    if(ch>='0' && ch<='9') return true;
    else return false;
}

void variableFunctionPartTypeB::parseVariableFunctionAsInput()
{
    int i;
    for(i=0;i<variableFunctionAsInput.size();i++)
    {
        if(variableFunctionAsInput[i]=='/') break;
        else if(variableFunctionAsInput[i]!=' ')
        {
            constantPart=constantPart=constantPart+variableFunctionAsInput[i];
        }
    } i++;
    int digitFlag=0;
    for(;i<variableFunctionAsInput.size();i++)
    {
        if(isDigit(variableFunctionAsInput[i]) && digitFlag==0)
        {
            parsedVariableFunctionAsInput=parsedVariableFunctionAsInput+'b';
            valueOfa=valueOfa+variableFunctionAsInput[i];
        }

        else if(isDigit(variableFunctionAsInput[i]) && digitFlag==1)
        {
            valueOfa=valueOfa+variableFunctionAsInput[i];
        }

        else
        {
            parsedVariableFunctionAsInput=parsedVariableFunctionAsInput
                    +variableFunctionAsInput[i];
        }
    }
}


