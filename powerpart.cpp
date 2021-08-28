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
    //cout << inputPower << "\n";
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

    else if(functionType==9)
    {
        computeOutputPowerForFunctionTypeNine();
    }
    //cout << outputPower << "\n";
}

void powerPart::computeOutputPowerForFunctionTypeOne()
{
    if(fractionStatus==0)
    {
        if(functionType==9) outputPower=inputPower;
    else {
    //stringstream ss;
    //convertedInputPower=atoi(inputPower.c_str());
    convertedInputPower=helping_Tools_1.convertStringToInt(inputPower);
    //cout << convertedInputPower << "\n";
    convertedOutputPower=convertedInputPower+1;
    //cout << convertedOutputPower << "\n";
    //ss<< convertedOutputPower;
    //outputPower=ss.str();
    outputPower=helping_Tools_1.convertIntToString(convertedOutputPower);
        }
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
        if(functionType==9)
        {
            numeratorAsOutput=numerator; denominatorAsOutput=denominator;
            outputPower=inputPower;
            //cout << outputPower << "\n";
        }
        else
        computeFractionalPowerAsOutput(numerator, denominator);
    }
}

void powerPart::computeOutputPowerForFunctionTypeNine()
{
    computeOutputPowerForFunctionTypeOne();
}

string powerPart::getOutputPower()
{
    if(functionType==9)
    {
        string temporaryOutputPower;
        //cout << outputPower << " " << outputPower.length() << "\n";
        for(int i=0;i<outputPower.length();i++)
        {
            if(outputPower[i]!='x') temporaryOutputPower+=outputPower[i];
            //cout << temporaryOutputPower << " " << outputPower[i] << "\n";
        }
        if(temporaryOutputPower.empty()) temporaryOutputPower="1";
        //cout << temporaryOutputPower << "\n";
        return temporaryOutputPower;
    }

    else
    {
        return outputPower;
    }
}


string powerPart::getOutputPowerWithX()
{
    //cout << outputPower << "\n";
    if(outputPower.empty())
    { return outputPower; }
    return ("("+outputPower+")");
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
    //int numeratorAsInt=atoi(numerator.c_str());
    long long int numeratorAsInt=
    helping_Tools_1.convertStringToInt(numerator);
    //int denominatorAsInt=atoi(denominator.c_str());
    long long int denominatorAsInt=
    helping_Tools_1.convertStringToInt(denominator);
    int numeratorAsIntFinal, denominatorAsIntFinal;

    numeratorAsIntFinal=numeratorAsInt+denominatorAsInt;
    denominatorAsIntFinal=denominatorAsInt;

    /*stringstream ss1;
    ss1<<numeratorAsIntFinal;
    processedNumerator=ss1.str();*/
    processedNumerator=helping_Tools_1.convertIntToString(numeratorAsIntFinal);

    /*stringstream ss2;
    ss2<<denominatorAsIntFinal;
    processedDenominator=ss2.str();*/
    processedDenominator=
    helping_Tools_1.convertIntToString(denominatorAsIntFinal);

    numeratorDenominatorSimplification(processedNumerator, processedDenominator);

    //cout << processedNumerator << " " << processedDenominator << endl;

    numeratorAsOutput=processedNumerator;
    denominatorAsOutput=processedDenominator;

    if(processedDenominator=="1")
    {
        outputPower=processedNumerator;
    }

    else
    {
        outputPower= processedNumerator+"/"+processedDenominator;
    }
}

void powerPart::numeratorDenominatorSimplification(string numerator, string denominator)
{
    //int numeratorAsInt=atoi(numerator.c_str());
    long long int numeratorAsInt=helping_Tools_1.convertStringToInt(numerator);
    //int denominatorAsInt=atoi(denominator.c_str());
    long long int denominatorAsInt=
    helping_Tools_1.convertStringToInt(denominator);

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

    processedNumerator=helping_Tools_1.convertIntToString(numeratorAsIntFinal);

    processedDenominator=helping_Tools_1.convertIntToString(denominatorAsIntFinal);
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
    if(functionType==9)
    {
        string temporaryNumerator;
        for(int i=0;i<numeratorAsOutput.length();i++)
        {
            if(numeratorAsOutput[i]!='x') temporaryNumerator+=numeratorAsOutput[i];
        }
        //cout << temporaryNumerator << "\n";
        return temporaryNumerator;
    }
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
