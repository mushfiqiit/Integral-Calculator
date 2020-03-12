#include "constantpart.h"
#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

constantPart::constantPart()
{
    fractionStatus=0;
}

void constantPart::setConstant(string constantStringAsInput)
{
    this->constantStringAsInput=constantStringAsInput;

}

string constantPart::getConstantStringAsInput()
{
    return constantStringAsInput;
}

void constantPart::formOutputConstant(string inputPower)
{
    computeOutputConstant(inputPower);
}

void constantPart::computeOutputConstant(string inputPower)
{
    stringstream ss;
    int inputPowerAsInt=atoi(inputPower.c_str());
    inputPowerAsInt=inputPowerAsInt+1;
    ss<<inputPowerAsInt;
    inputPower=ss.str();

    if(constantStringAsInput=="" || constantStringAsInput.empty())
    {
        constantStringAsInput="1";
    }

    if(fractionStatus==0)  //Calculation when constant part is not a fraction
    {
    initialNumerator=constantStringAsInput;
    initialDenominator=inputPower;
   /* cout << initialNumerator << endl;
    cout << initialDenominator << endl; */
    }

    else  // Calculation when constant part is a fraction
    {
        computeFractionNumeratorDenominator(constantStringAsInput, inputPower);
    }

    numeratorDenominatorSimplification(initialNumerator, initialDenominator);

    if(processedDenominator=="1")
    {
        outputConstant="(" +processedNumerator +")";
    }

    else
    {
    outputConstant="("+processedNumerator+"/"+processedDenominator+")";
    }
}

string constantPart::getOutputConstant()
{
    return outputConstant;
}

void constantPart::numeratorDenominatorSimplification(string numerator, string denominator)
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

void constantPart::setFractionStatus(int fractionStatus)
{
    this->
    fractionStatus=fractionStatus;
}

void constantPart::computeFractionNumeratorDenominator(string constantStringAsInput,
                                                       string inputPower)
{
    int i;
    string fractionStatusInitialNumerator;
    string fractionStatusInitialDenominator;

    //Parsing Numerator of fraction
    for(i=0;i<constantStringAsInput.size();i++)
    {
        if(constantStringAsInput[i]=='/')
        {
            break;
        }

        else if(constantStringAsInput[i]=='(')
        {
            continue;
        }

        else
        {
            fractionStatusInitialNumerator=fractionStatusInitialNumerator+constantStringAsInput[i];
        }
    }
    //**********************
    i++;

    //Parsing denominator part of fraction

    for(;i<constantStringAsInput.size();i++)
    {
        if(constantStringAsInput[i]==')')
        {
            break;
        }
        fractionStatusInitialDenominator=fractionStatusInitialDenominator+constantStringAsInput[i];
    }
    //**************************

int fractionStatusNumeratorAsInt=atoi(fractionStatusInitialNumerator.c_str());
int fractionStatusDenominatorAsInt=atoi(fractionStatusInitialDenominator.c_str());
int inputPowerAsInt=atoi(inputPower.c_str());



fractionStatusDenominatorAsInt=fractionStatusDenominatorAsInt*inputPowerAsInt;


stringstream ss1, ss2;
ss1<<fractionStatusNumeratorAsInt;
initialNumerator=ss1.str();
ss2<<fractionStatusDenominatorAsInt;
initialDenominator=ss2.str();
}

int constantPart::getFractionStatus()
{
    return fractionStatus;
}
