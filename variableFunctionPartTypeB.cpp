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

string variableFunctionPartTypeB::getVariableFunctionAsOutput() // 3
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


void variableFunctionPartTypeB::setVariableFunctionType(int functionType) // 6
{
    this->variableFunctionType=functionType;
}


string variableFunctionPartTypeB::getConstantPart() // 7
{
    return this->constantPart;
}


void variableFunctionPartTypeB::formVariableFunctionAsOutput() // 8
{
    computeVariableFunctionAsOutput();
}


string variableFunctionPartTypeB::getValueOfaNumerator() // 9
{
    return this->valueOfaNumerator;
}

string variableFunctionPartTypeB::getValueOfaDenominator() // 10
{
    return this->valueOfaDenominator;
}

int variableFunctionPartTypeB::getIsRootValueOfaNumerator()
{
    return this->isRootValueOfaNumerator;
}

int variableFunctionPartTypeB::getIsRootValueOfaDenominator()
{
    return this->isRootValueOfaDenominator;
}

// ***************     Private Part     ******************


bool variableFunctionPartTypeB::isDigit(char ch) // 11
{
    if((ch>='0' && ch<='9')||ch=='/') return true;
    else return false;
}


bool variableFunctionPartTypeB::isPerfectSquare(int numberToCheck) // 12
{
    if(sqrt(numberToCheck)*sqrt(numberToCheck)==numberToCheck) return true;
    else return false;
}

string variableFunctionPartTypeB::parseVariableFunctionAsInput(string variableFunctionToParse)//13
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
    int digitFlag=0, powerFlag=0;
    for(;i<variableFunctionToParse.size();i++)
    {
        //cout << variableFunctionToParse[i] << " " << digitFlag << "\n";
        //if(isDigit(variableFunctionToParse[i])) cout << "Yes \n";
        if(variableFunctionToParse[i]=='^') powerFlag=1;

        if(isDigit(variableFunctionToParse[i]) && digitFlag==0
           && variableFunctionToParse[i-1]!='^' && powerFlag==0)
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
            if(!isDigit(variableFunctionToParse[i]) &&
               variableFunctionToParse[i]!='^' && variableFunctionToParse[i]!='/') powerFlag=0;
            parsedVariableFunctionAsInput=parsedVariableFunctionAsInput
                    +variableFunctionToParse[i];
            digitFlag=0;
        }
    }
    //cout << parsedVariableFunctionAsInput << "\n";
    return parsedVariableFunctionAsInput;
}

int variableFunctionPartTypeB::identifyFunctionTypeB(string variableFunctionToIdentify) //14
{
    //cout << variableFunctionToIdentify << "\n";
    if(variableFunctionToIdentify=="a+x^2") return 10;
    else if(variableFunctionToIdentify=="a-x^2^1/2") { return 11; }
    else if(variableFunctionToIdentify=="a-x^2") { return 12; }
    else if(variableFunctionToIdentify=="x^2-a") { return 13; }
    else return 0;
}


void variableFunctionPartTypeB::computeVariableFunctionAsOutput() // 16
{
    if(variableFunctionType==10)
    {
        computeVariableFunctionAsOutputForFunctionTypeTen();
    }

    else if(variableFunctionType==11)
    {
        computeVariableFunctionAsOutputForFunctionTypeEleven();
    }

    else if(variableFunctionType==12)
    {
        computeVariableFunctionAsOutputForFunctionTypeTwelve();
    }

    else if(variableFunctionType==13)
    {
        computeVariableFunctionAsOutputForFunctionTypeThirteen();
    }
}

void variableFunctionPartTypeB::computeVariableFunctionAsOutputForFunctionTypeTen() // 17
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


void variableFunctionPartTypeB::computeVariableFunctionAsOutputForFunctionTypeEleven()
{
    variableFunctionAsOutput="sin^-1(";
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


void variableFunctionPartTypeB::computeVariableFunctionAsOutputForFunctionTypeTwelve()
{
    variableFunctionAsOutput="ln((";
    valueOfaNumeratorDenominatorSeperation();
    valueOfaNumeratorDenominatorCalculation();
    if(valueOfaDenominator=="1")
    {
        valueOfa=valueOfaNumerator;
        variableFunctionAsOutput=variableFunctionAsOutput+valueOfa + "+x)/(" +
                valueOfa + "-x))";
    }

    else
    {
        variableFunctionAsOutput=variableFunctionAsOutput+valueOfaNumerator + "+" +
        valueOfaDenominator + "*x)/(" + valueOfaNumerator + "-" + valueOfaDenominator + "*x))";
    }
}


void variableFunctionPartTypeB::computeVariableFunctionAsOutputForFunctionTypeThirteen()
{
    variableFunctionAsOutput="ln((";
    valueOfaNumeratorDenominatorSeperation();
    valueOfaNumeratorDenominatorCalculation();
    if(valueOfaDenominator=="1")
    {
        valueOfa=valueOfaNumerator;
        variableFunctionAsOutput=variableFunctionAsOutput+ "x-" + valueOfa + ")/(" +
                "x+" + valueOfa + "))";
    }

    else
    {
        variableFunctionAsOutput=variableFunctionAsOutput+ valueOfaDenominator + "*x" + "-" +
        valueOfaNumerator + ")/(" +valueOfaDenominator + "*x+" + valueOfaNumerator +  "))";
    }
}



string variableFunctionPartTypeB::constantAndMainFunctionSeperation // 18
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

void variableFunctionPartTypeB::valueOfaNumeratorDenominatorSeperation() // 18
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

void variableFunctionPartTypeB::valueOfaNumeratorDenominatorCalculation() // 19
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
        isRootValueOfaNumerator=0;
    }

    else
    {
        valueOfaNumerator="(" + valueOfaSquareNumerator+ "^(1/2))";
        isRootValueOfaNumerator=1;
    }

    if(isPerfectSquare(valueOfaSquareDenominatorAsInt))
    {
        valueOfaDenominatorAsInt=sqrt(valueOfaSquareDenominatorAsInt);
        valueOfaDenominator=helping_tools_1.convertIntToString(valueOfaDenominatorAsInt);
        isRootValueOfaDenominator=0;
    }

    else
    {
        valueOfaDenominator="(" + valueOfaSquareDenominator+"^(1/2))";
        isRootValueOfaDenominator=1;
    }
    //cout << valueOfaNumerator << " " << valueOfaDenominator << "\n";
}

