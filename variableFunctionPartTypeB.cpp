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
    //cout << variableFunctionToParse << "\n";
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
    //cout << parsedVariableFunctionAsInput << "\n";
    return parsedVariableFunctionAsInput;
}

int variableFunctionPartTypeB::identifyFunctionTypeB(string variableFunctionToIdentify)
{
    //cout << variableFunctionToIdentify << "\n";
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
    variableFunctionAsOutput="tan^-1(";
    valueOfaNumeratorDenominatorSeperation();
    valueOfaNumeratorDenominatorCalculation();
    string partToAdd="x";
    if(valueOfaDenominator!="1")
    {
        partToAdd="(" + partToAdd+ "*" +valueOfaDenominator+")";
    }

    if(valueOfaNumerator!="1")
    {
        partToAdd="(" + partToAdd + "/" + valueOfaNumerator + ")";
    }
    variableFunctionAsOutput=variableFunctionAsOutput+partToAdd;
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
        //cout << variableFunctionToSeperate[i] << " num\n";
        if(variableFunctionToSeperate[i]=='/' || variableFunctionToSeperate[i]==')') break;
        else if(variableFunctionToSeperate[i]!='(' || variableFunctionToSeperate[i]!=' ')
        {
            parsedNumerator=parsedNumerator+variableFunctionToSeperate[i];
        }
    }
    if(variableFunctionToSeperate[i]=='/')i++;
    int leftBracketCounter=0;
    for(;i<variableFunctionToSeperate.length();i++)
    {
        //cout << variableFunctionToSeperate[i] << "den\n";
        if(variableFunctionToSeperate[i]==')')
        {
            if(leftBracketCounter==0)
                {parsedDenominator=parsedDenominator+")"; break;}
            else
                leftBracketCounter--;
        }
        else if(variableFunctionToSeperate[i]=='+' || variableFunctionToSeperate[i]=='x')
        {
            notConstantFlag=1;
            parsedDenominator=parsedDenominator+variableFunctionToSeperate[i];
        }

        else if(variableFunctionToSeperate[i]!=' ')
        {
            parsedDenominator=parsedDenominator+variableFunctionToSeperate[i];
            if(variableFunctionToSeperate[i]=='(')
            {
                leftBracketCounter++;
            }
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

void variableFunctionPartTypeB::valueOfaNumeratorDenominatorSeperation()
{
    int i;
    for(i=0;i<valueOfaSquare.length();i++)
    {
        if(valueOfaSquare[i]==')' || valueOfaSquare[i]=='/') break;
        else if(valueOfaSquare[i]!='(' || valueOfaSquare[i]!=' ')
        {
            valueOfaSquareNumerator=valueOfaSquareNumerator+valueOfaSquare[i];
        }
    } i++;
    for(;i<valueOfaSquare.length();i++)
    {
        if(valueOfaSquare[i]!=')' || valueOfaSquare[i]!=' ' || valueOfaSquare[i]!='(')
        {
            valueOfaSquareDenominator=valueOfaSquareDenominator+valueOfaSquare[i];
        }
    }
    //cout << valueOfaSquareNumerator << " " << valueOfaSquareDenominator << "\n";
}

void variableFunctionPartTypeB::valueOfaNumeratorDenominatorCalculation()
{
    valueOfaSquareNumeratorAsInt=helping_tools_1.convertStringToInt
                        (valueOfaSquareNumerator);
    if(!valueOfaSquareDenominator.empty())
    valueOfaSquareDenominatorAsInt=helping_tools_1.convertStringToInt
                        (valueOfaSquareDenominator);
    else
    valueOfaSquareDenominatorAsInt=1;

    if(isPerfectSquare(valueOfaSquareNumeratorAsInt))
    {
        valueOfaNumeratorAsInt=sqrt(valueOfaSquareNumeratorAsInt);
        valueOfaNumerator=helping_tools_1.convertIntToString(valueOfaNumeratorAsInt);
    }

    else
    {
        valueOfaNumerator="(" + valueOfaSquareNumerator+ "^(1/2))";
    }

    if(isPerfectSquare(valueOfaSquareDenominatorAsInt))
    {
        valueOfaDenominatorAsInt=sqrt(valueOfaSquareDenominatorAsInt);
        valueOfaDenominator=helping_tools_1.convertIntToString(valueOfaDenominatorAsInt);
    }

    else
    {
        valueOfaDenominator="(" + valueOfaSquareDenominator+"^(1/2))";
    }
    //cout << valueOfaNumerator << " " << valueOfaDenominator << "\n";
}

string variableFunctionPartTypeB::getValueOfaNumerator()
{
    return this->valueOfaNumerator;
}

string variableFunctionPartTypeB::getValueOfaDenominator()
{
    return this->valueOfaDenominator;
}

