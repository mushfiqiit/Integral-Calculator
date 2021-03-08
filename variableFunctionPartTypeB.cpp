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
    if((ch>='0' && ch<='9')||ch=='/') return true;
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
    variableFunctionToParse=constantAndMainFunctionSeperation(variableFunctionToParse);
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
        //cout << variableFunctionToParse[i] << " " << digitFlag << "\n";
        //if(isDigit(variableFunctionToParse[i])) cout << "Yes \n";
        if(isDigit(variableFunctionToParse[i]) && digitFlag==0 && variableFunctionToParse[i-1]!='^')
        {
            //cout << "1\n";
            parsedVariableFunctionAsInput=parsedVariableFunctionAsInput+"a";
            digitFlag=1;
            valueOfaSquare=valueOfa+variableFunctionToParse[i];
        }

        else if(isDigit(variableFunctionToParse[i])
                 && digitFlag==1)
        {
            //cout << "2\n";
            valueOfaSquare=valueOfaSquare+variableFunctionToParse[i];
        }

        else if(variableFunctionToParse[i]!=' ' && variableFunctionToParse[i]!='('
                                                && variableFunctionToParse[i]!=')')
        {
            //cout << "3\n";
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
    if(variableFunctionToIdentify=="a+x^2") return 10;
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
    variableFunctionAsOutput="tan^-1(x";
    valueOfaSquareAsInt=atoi(valueOfaSquare.c_str());
    if(valueOfaSquareAsInt!=1)
    {
        variableFunctionAsOutput=variableFunctionAsOutput+"/";
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


string variableFunctionPartTypeB::constantAndMainFunctionSeperation
(string variableFunctionToSeperate)
{
    string parsedNumerator, parsedDenominator;
    string seperatedVariableFunction;
    int i=0;
    int notConstantFlag=0;
    for(;i<variableFunctionToSeperate.length();i++)
    {
        if(variableFunctionToSeperate[i]=='/' || variableFunctionToSeperate[i]==')') break;
        else if(variableFunctionToSeperate[i]!='(' || variableFunctionToSeperate[i]!=' ')
        {
            parsedNumerator=parsedNumerator+variableFunctionToSeperate[i];
        }
    }
    if(variableFunctionToSeperate[i]=='/')i++;
    for(;i<variableFunctionToSeperate.length();i++)
    {
        if(variableFunctionToSeperate[i]==')') {parsedDenominator=parsedDenominator+")"; break;}
        else if(variableFunctionToSeperate[i]=='+' || variableFunctionToSeperate[i]=='x')
        {
            notConstantFlag=1;
            parsedDenominator=parsedDenominator+variableFunctionToSeperate[i];
        }

        else if(variableFunctionToSeperate[i]!=' ')
        {
            parsedDenominator=parsedDenominator+variableFunctionToSeperate[i];
        }
    }

    if(notConstantFlag==0)
    {
        if(parsedDenominator!=")")
        this->constantPart=parsedNumerator+"/" + parsedDenominator;
        else
        this->constantPart=parsedNumerator+")";
        //cout << constantPart << "\n";
        i++;
        for(;i<variableFunctionToSeperate.length();i++)
        {
            seperatedVariableFunction=seperatedVariableFunction+variableFunctionToSeperate[i];
        }
    }

    else
    {
        seperatedVariableFunction=variableFunctionToSeperate;
    }
    return seperatedVariableFunction;
}
