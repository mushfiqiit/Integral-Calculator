#include "constantpart.h"
#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

constantPart::constantPart()
{

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
    ss>>inputPower;

    if(constantStringAsInput=="" || constantStringAsInput.empty())
    {
        constantStringAsInput="1";
    }
    numeratorDenominatorSimplification(constantStringAsInput, inputPower);

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


    stringstream ss1;
    stringstream ss2;
    ss1 <<numeratorAsIntFinal;
    ss1 >>processedNumerator;

    ss2 <<denominatorAsIntFinal;
    ss2 >>processedDenominator;
}
