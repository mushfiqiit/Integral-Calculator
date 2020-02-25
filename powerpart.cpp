#include "powerpart.h"
#include <bits/stdc++.h>
#include <string>

using namespace std;

powerPart::powerPart()
{

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
    computeOutputPower();
}

void powerPart::computeOutputPower()
{
    stringstream ss;
    convertedInputPower=atoi(inputPower.c_str());
    convertedOutputPower=convertedInputPower+1;
    ss<< convertedOutputPower;
    outputPower=ss.str();
}

string powerPart::getOutputPower()
{
    return outputPower;
}
