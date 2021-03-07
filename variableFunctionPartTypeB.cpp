#include "variableFunctionPartTypeB.h"
#include <bits/stdc++.h>

using namespace std;

variableFunctionPartTypeB::variableFunctionPartTypeB() // 1
{
    //ctor
}

void variableFunctionPartTypeB::setVariableFunctionPart(string variableFunctionAsInput) // 2
{
    this->variableFunctionAsInput=variableFunctionAsInput;
}

string variableFunctionPartTypeB::getVariableFunctionAsOutput()
{
    return this->variableFunctionAsOutput;
}

int variableFunctionPartTypeB::getfunctionType(string variableFunctionToIdentify) // 4
{
    string parsedVariableFunction=parseVariableFunctionAsInput(variableFunctionToIdentify);
    //cout << parsedVariableFunction << "\n";
    variableFunctionAsInput=parsedVariableFunction;
    int functionType=identifyFunctionTypeB(parsedVariableFunction);
    setVariableFunctionType(functionType);
    return functionType;
}


bool variableFunctionPartTypeB::isDigit(char ch)
{
    if(ch>='0' && ch<='9') return true;
    else return false;
}

bool variableFunctionPartTypeB::isPerfectSquare(int numberToCheck)
{
    if(sqrt(numberToCheck)*sqrt(numberToCheck)==numberToCheck) return true;
    else return false;
}

string variableFunctionPartTypeB::parseVariableFunctionAsInput(string variableFunctionToParse)
{
    int i;
    string parsedVariableFunctionAsInput;
    for(i=0;i<variableFunctionToParse.size();i++)
    {
        if(variableFunctionToParse[i]=='/') break;
        else if(variableFunctionToParse[i]!=' ')
        {
            constantPartNumerator=constantPartNumerator+variableFunctionToParse[i];
        }
    } i++;
    int digitFlag=0;
    for(;i<variableFunctionToParse.size();i++)
    {
        if(isDigit(variableFunctionToParse[i]) && digitFlag==0 && variableFunctionToParse[i-1]!='^')
        {
            parsedVariableFunctionAsInput=parsedVariableFunctionAsInput+"a";
            digitFlag=1;
            valueOfaSquare=valueOfa+variableFunctionToParse[i];
        }

        else if(isDigit(variableFunctionAsInput[i]) && digitFlag==1)
        {
            valueOfaSquare=valueOfaSquare+variableFunctionToParse[i];
        }

        else if(variableFunctionToParse[i]!=' ')
        {
            parsedVariableFunctionAsInput=parsedVariableFunctionAsInput
                    +variableFunctionToParse[i];
            digitFlag=0;
        }
    }
    return parsedVariableFunctionAsInput;
}

int variableFunctionPartTypeB::identifyFunctionTypeB(string variableFunctionToIdentify)
{
    cout << variableFunctionToIdentify << "\n";
    if(variableFunctionToIdentify=="(a+x^2)") return 10;
    else return 0;
}


void variableFunctionPartTypeB::setVariableFunctionType(int functionType)
{
    this->variableFunctionType=functionType;
}

string variableFunctionPartTypeB::getConstantPart()
{
    return this->constantPart;
}

void variableFunctionPartTypeB::formVariableFunctionAsOutput()
{
    computeVariableFunctionAsOutput();
}

void variableFunctionPartTypeB::computeVariableFunctionAsOutput()
{
    if(variableFunctionType==10)
    {
        computeVariableFunctionAsOutputForFunctionTypeTen();
    }
}

void variableFunctionPartTypeB::computeVariableFunctionAsOutputForFunctionTypeTen()
{
    variableFunctionAsOutput="tan^-1(x/";
    valueOfaSquareAsInt=atoi(valueOfaSquare.c_str());
    if(valueOfaSquareAsInt!=1)
    {
        if(isPerfectSquare(valueOfaSquareAsInt))
        {
            valueOfaAsInt=sqrt(valueOfaSquareAsInt);
            stringstream ss;
            ss<<valueOfaAsInt;
            valueOfa=ss.str();
            variableFunctionAsOutput=variableFunctionAsOutput+valueOfa;
        }

        else
        {
            variableFunctionAsOutput=variableFunctionAsOutput+"( " + valueOfaSquare
                    +"^(1/2) )";
        }
    }
    variableFunctionAsOutput=variableFunctionAsOutput+")";
}

