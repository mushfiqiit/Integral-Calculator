#include "powerpart.h"
#include <bits/stdc++.h>
#include <string>

using namespace std;

powerPart::powerPart()
{
    fractionStatus=0;
}

void powerPart::setInputPower(string inputPower)
{
    this->inputPower=inputPower;
}

string powerPart::getInputPower()
{
    return inputPower;
}

void powerPart::formOutputPower()
{
    if(functionType==1)
    {
    computeOutputPowerForFunctionTypeOne();
    }

    else if(functionType==2)
    {

    }
}

void powerPart::computeOutputPowerForFunctionTypeOne()
{
    if(fractionStatus==0)
    {
    stringstream ss;
    convertedInputPower=atoi(inputPower.c_str());
    convertedOutputPower=convertedInputPower+1;
    ss<< convertedOutputPower;
    outputPower=ss.str();
    }

    else if(fractionStatus==1)
    {
        int i;
        // Parsing Numerator
        for(i=0;i<inputPower.length();i++)
        {
            if(inputPower[i]=='/')
            {
                break;
            }

            else if(inputPower[i]=='(')
            {
                continue;
            }

            else
            {
            numerator=numerator+inputPower[i];
            }
        }
        //***************
        i++;

        //Parsing Denominator
        for(;i<inputPower.length();i++)
        {
            if(inputPower[i]==')')
            {
                break;
            }

            else
            {
            denominator=denominator+inputPower[i];
            }
        }
        //**********************

        computeFractionalPowerAsOutput(numerator, denominator);
    }
}

string powerPart::getOutputPower()
{
    return outputPower;
}

void powerPart::setFractionStatus(int fractionStatus)
{
    this->fractionStatus=fractionStatus;
}

int powerPart::getFractionStatus()
{
    return fractionStatus;
}

void powerPart::computeFractionalPowerAsOutput(string numerator, string denominator)
{
    int numeratorAsInt=atoi(numerator.c_str());
    int denominatorAsInt=atoi(denominator.c_str());
    int numeratorAsIntFinal, denominatorAsIntFinal;

    numeratorAsIntFinal=numeratorAsInt+denominatorAsInt;
    denominatorAsIntFinal=denominatorAsInt;

    stringstream ss1;
    ss1<<numeratorAsIntFinal;
    processedNumerator=ss1.str();

    stringstream ss2;
    ss2<<denominatorAsIntFinal;
    processedDenominator=ss2.str();

    numeratorDenominatorSimplification(processedNumerator, processedDenominator);

    //cout << processedNumerator << " " << processedDenominator << endl;

    numeratorAsOutput=processedNumerator;
    denominatorAsOutput=processedDenominator;

    outputPower= "("+processedNumerator+"/"+processedDenominator+")";
}

void powerPart::numeratorDenominatorSimplification(string numerator, string denominator)
{
    int numeratorAsInt=atoi(numerator.c_str());
    int denominatorAsInt=atoi(denominator.c_str());
    int numeratorAsIntFinal, denominatorAsIntFinal;

    numeratorAsIntFinal=numeratorAsInt/__gcd(numeratorAsInt, denominatorAsInt);
    denominatorAsIntFinal=denominatorAsInt/__gcd(numeratorAsInt, denominatorAsInt);

    if(numeratorAsIntFinal<0 && denominatorAsIntFinal<0)
    {
        numeratorAsIntFinal=abs(numeratorAsIntFinal);
        denominatorAsIntFinal=denominatorAsIntFinal;
    }

    else if((numeratorAsIntFinal<0 && denominatorAsIntFinal>0)||
            (numeratorAsIntFinal>0 && denominatorAsIntFinal<0))
    {
        if(numeratorAsIntFinal>0)
        {
            numeratorAsIntFinal=-numeratorAsIntFinal;
            denominatorAsIntFinal=abs(denominatorAsIntFinal);
        }
    }


    stringstream ss1;
    stringstream ss2;
    ss1 <<numeratorAsIntFinal;
    processedNumerator=ss1.str();

    ss2 <<denominatorAsIntFinal;
    processedDenominator=ss2.str();
}

string powerPart::getNumerator()
{
    return numerator;
}

string powerPart::getDenominator()
{
    return denominator;
}

string powerPart::getNumeratorAsOutput()
{
    return numeratorAsOutput;
}

string powerPart::getDenominatorAsOutput()
{
    return denominatorAsOutput;
}

void powerPart::setFunctionType(int functionTypeCode)
{
    this->functionType=functionTypeCode;
}
