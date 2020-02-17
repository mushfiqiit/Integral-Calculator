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

    outputConstant=constantStringAsInput+"/"+inputPower;
}

string constantPart::getOutputConstant()
{
    return outputConstant;
}
