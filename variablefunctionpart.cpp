#include "variablefunctionpart.h"
#include <bits/stdc++.h>

using namespace std;

variableFunctionPart::variableFunctionPart() // 1
{

}

void variableFunctionPart::setVariableFunctionAsInput(string variableFunctionAsInput) // 2
{
    this->variableFunctionAsInput=variableFunctionAsInput;

    //cout <<variableFunctionAsInput << "\n";

    if(functionType==3 || functionType==4 || functionType==5 || functionType==6)
    {
        int i;
        if(functionType==3 || functionType==4)
        {
            i=0;
        }

        else if(functionType==5)
        {
            i=5;
        }

        else if(functionType==6)
        {
            i=7;
        }

        for(;i<variableFunctionAsInput.length();i++)
        {
            if(variableFunctionAsInput[i]=='/')
            {
                coefficient_Part_1.setFractionStatus(1);
            }

            //cout << variableFunctionAsInput[i] << endl;
            if((variableFunctionAsInput[i]>='0' && variableFunctionAsInput[i]<='9')
               || variableFunctionAsInput[i]=='/')
            {
                coefficientStringAsInput=coefficientStringAsInput+variableFunctionAsInput[i];
            }
        }
        //cout << coefficientStringAsInput << endl;

    }

    else if(functionType==7)
    {
        for(int i=0;i<variableFunctionAsInput.length();i++)
        {
            if(variableFunctionAsInput[i]=='t') break;

            if(variableFunctionAsInput[i]=='/')
            {
                coefficient_Part_1.setFractionStatus(1);
            }

            //cout << variableFunctionAsInput[i] << endl;
            if((variableFunctionAsInput[i]>='0' && variableFunctionAsInput[i]<='9')
               || variableFunctionAsInput[i]=='/')
            {
                coefficientStringAsInput=coefficientStringAsInput+variableFunctionAsInput[i];
            }
        }
        //cout << coefficientStringAsInput << "\n";
    }

    else if(functionType==8)
    {
        int counter=0;
        for(int i=0;i<variableFunctionAsInput.length();i++)
        {
            if(variableFunctionAsInput[i]=='c') counter++; if(counter>2) break;

            if(variableFunctionAsInput[i]=='/')
            {
                coefficient_Part_1.setFractionStatus(1);
            }

            //cout << variableFunctionAsInput[i] << endl;
            if(((variableFunctionAsInput[i]>='0' && variableFunctionAsInput[i]<='9')
               || (variableFunctionAsInput[i]=='/')) && counter==2)
            {
                coefficientStringAsInput=coefficientStringAsInput+variableFunctionAsInput[i];
            }
        }
    }
    coefficient_Part_1.setCoeffficientAsInput(coefficientStringAsInput);
}

string variableFunctionPart::getVariableFunctionAsInput()
{
    return variableFunctionAsInput;
}

bool variableFunctionPart::functionIsX() // 4
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

bool variableFunctionPart::functionIsEmpty() // 5
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

void variableFunctionPart::setFunctionType(int functionTypeCode) // 6
{
    this->functionType=functionTypeCode;
    //cout << functionType << " " << functionTypeCode << endl;
}



string variableFunctionPart::getOutputVariableFunction() // 7
{
    return this->outputVariableFunction;
}

void variableFunctionPart::formOutputVariableFunction() // 8
{
    //cout << functionType << endl;
    if(functionType==1) computeOutputVariableFunctionForFunctionTypeOne();

    else if(functionType==2) computeOutputVariableFunctionForFunctionTypeTwo();

    else if(functionType==3) computeOutputVariableFunctionForFunctionTypeThree();

    else if(functionType==4) computeOutputVariableFunctionForFunctionTypeFour();

    else if(functionType==5) computeOutputVariableFunctionForFunctionTypeFive();

    else if(functionType==6) computeOutputVariableFunctionForFunctionTypeSix();

    else if(functionType==7) computeOutputVariableFunctionForFunctionTypeSeven();

    else if(functionType==8) computeOutputVariableFunctionForFunctionTypeEight();

    else if(functionType==9) computeOutputVariableFunctionForFunctionTypeNine();
}

string variableFunctionPart::getCoefficientStringAsInput() // 9
{
    this->coefficientStringAsInput=coefficient_Part_1.getCoefficientAsInput();
    return this->coefficientStringAsInput;
}

int variableFunctionPart::getCoefficientFractionStatus() // 10
{
    return this->coefficient_Part_1.getFractionStatus();
}

string variableFunctionPart::getCoefficientNumerator() // 11
{
    return this->coefficient_Part_1.getCoefficientNumerator();
}

string variableFunctionPart::getCoefficientDenominator() // 12
{
    return this->coefficient_Part_1.getCoefficientDenominator();
}




void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeOne()
{
    outputVariableFunction=variableFunctionAsInput;
}


void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeTwo()
{
    outputVariableFunction="ln" + variableFunctionAsInput;
}



void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeThree()
{
    if(coefficient_Part_1.getFractionStatus()==0)
    {
        outputVariableFunction=outputVariableFunction+"cos" + "(" +
                                coefficientStringAsInput + "x" + ")";
    }

    else
    {
        outputVariableFunction=outputVariableFunction+"cos" + "(" +
                coefficient_Part_1.getCoefficientNumerator() + "x"
                + "/" + coefficient_Part_1.getCoefficientDenominator()
                + ")";
    }
}

void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeFour()
{
    if(coefficient_Part_1.getFractionStatus()==0)
    {
        outputVariableFunction=outputVariableFunction+"sin" + "(" +
                            coefficientStringAsInput + "x" + ")";
    }

    else
    {
        outputVariableFunction=outputVariableFunction+"sin" + "("
                +coefficient_Part_1.getCoefficientNumerator() + "x"
                + "/" + coefficient_Part_1.getCoefficientDenominator()
                + ")";
    }
}

void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeFive()
{
    if(coefficient_Part_1.getFractionStatus()==0)
    {
        outputVariableFunction=outputVariableFunction+"tan" + "(" +
                                coefficientStringAsInput + "x" + ")";
    }

    else
    {
        outputVariableFunction=outputVariableFunction+"tan" + "("
                +coefficient_Part_1.getCoefficientNumerator() + "x"
                + "/" + coefficient_Part_1.getCoefficientDenominator()
                + ")";
    }
}

void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeSix()
{
    //cout << "here" << "\n";
    if(coefficient_Part_1.getFractionStatus()==0)
    {
        outputVariableFunction=outputVariableFunction+"cot" + "(" + coefficientStringAsInput
                                +"x" + ")";
    }

    else
    {
        outputVariableFunction=outputVariableFunction+"cot" + "("
                +coefficient_Part_1.getCoefficientNumerator() + "x"
                + "/" + coefficient_Part_1.getCoefficientDenominator()
                + ")";
    }
}

void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeSeven()
{
    if(coefficient_Part_1.getFractionStatus()==0)
    {
        outputVariableFunction=outputVariableFunction+"sec" + "(" + coefficientStringAsInput
                                +"x" + ")";
    }

    else
    {
        outputVariableFunction=outputVariableFunction+"sec" + "("
                +coefficient_Part_1.getCoefficientNumerator() + "x"
                + "/" + coefficient_Part_1.getCoefficientDenominator()
                + ")";
    }
}

void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeEight()
{
    if(coefficient_Part_1.getFractionStatus()==0)
    {
        outputVariableFunction=outputVariableFunction+"cosec" + "(" + coefficientStringAsInput
                                +"x" + ")";
    }

    else
    {
        outputVariableFunction=outputVariableFunction+"cosec" + "("
                +coefficient_Part_1.getCoefficientNumerator() + "x"
                + "/" + coefficient_Part_1.getCoefficientDenominator()
                + ")";
    }
}

void variableFunctionPart::computeOutputVariableFunctionForFunctionTypeNine()
{
    outputVariableFunction="e";
}
