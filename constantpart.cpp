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

void constantPart::formOutputConstant()
{
    if(functionType==1) computeOutputConstantForFunctionTypeOne();

    else if(functionType==2) computeOutputConstantForFunctionTypeTwo();

    else if(functionType==3) computeOutputConstantForFunctionTypeThree();

    else if(functionType==4) computeOutputConstantForFunctionTypeFour();

    else if(functionType==5) computeOutputConstantForFunctionTypeFive();

    else if(functionType==6) computeOutputConstantForFunctionTypeSix();

    else if(functionType==7) computeOutputConstantForFunctionTypeSeven();

    else if(functionType==8) computeOutputConstantForFunctionTypeEight();

    else if(functionType==9) computeOutputConstantForFunctionTypeNine();

    else if(functionType==10) computeOutputConstantForFunctionTypeTen();

    else if(functionType==12 || functionType==13) computeOutputConstantForFunctionTypeTwelve();

    else if(functionType==11) computeOutputConstantForFunctionTypeTwo();
}

void constantPart::computeOutputConstantForFunctionTypeOne()
{
    /*stringstream ss;
    int outputPowerAsInt=atoi(inputPower.c_str());
    ss<<inputPowerAsInt;
    inputPower=ss.str(); */

    if(constantStringAsInput=="" || constantStringAsInput.empty())
    {
        constantStringAsInput="1";
    }

    if(fractionStatus==0)  //Calculation when constant part is not a fraction
    {
    initialNumerator=constantStringAsInput;
    initialDenominator="1";
    }

    else
    {
        parseFractionConstant(constantStringAsInput);
    }

    computeFractionNumeratorDenominator(initialNumerator, initialDenominator);


    //cout << initialNumerator << " " << initialDenominator << endl;
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
    //int numeratorAsInt=atoi(numerator.c_str());
    long long int numeratorAsInt=helping_tools_1.convertStringToInt(numerator);
    //int denominatorAsInt=atoi(denominator.c_str());
    long long int denominatorAsInt=
    helping_tools_1.convertStringToInt(denominator);
    int numeratorAsIntFinal, denominatorAsIntFinal;
    //cout << numeratorAsInt << " " << denominatorAsInt << endl;
    //cout << numerator << " " << denominator << "\n";

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

    //cout << numeratorAsIntFinal << " " << denominatorAsIntFinal << "\n";
    processedNumerator=helping_tools_1.convertIntToString(numeratorAsIntFinal);

    processedDenominator=helping_tools_1.convertIntToString(denominatorAsIntFinal);
    //cout << numerator << " " << denominator << "\n";
}

void constantPart::setFractionStatus(int fractionStatus)
{
    this->fractionStatus=fractionStatus;
}

void constantPart::computeFractionNumeratorDenominator(string initialNumerator,
                                                    string initialDenominator)
{
    int i;
    string fractionStatusInitialNumerator;
    string fractionStatusInitialDenominator;

    fractionStatusInitialNumerator=initialNumerator;
    fractionStatusInitialDenominator=initialDenominator;

long long int fractionStatusNumeratorAsInt=
helping_tools_1.convertStringToInt(fractionStatusInitialNumerator);

//atoi(fractionStatusInitialNumerator.c_str());

long long int fractionStatusDenominatorAsInt=
helping_tools_1.convertStringToInt(fractionStatusInitialDenominator);


//atoi(fractionStatusInitialDenominator.c_str());

//cout << fractionStatusNumeratorAsInt << " " << fractionStatusDenominatorAsInt << endl;

int outputPowerNumeratorAsInt=atoi(outputPowerNumerator.c_str());
int outputPowerDenominatorAsInt=atoi(outputPowerDenominator.c_str());

if(functionType==3 || functionType==6 || functionType==8)
{
    fractionStatusNumeratorAsInt=-fractionStatusNumeratorAsInt;
}

//cout << outputPowerNumeratorAsInt << " " << outputPowerDenominatorAsInt << endl;

fractionStatusNumeratorAsInt=fractionStatusNumeratorAsInt*outputPowerDenominatorAsInt;
fractionStatusDenominatorAsInt=(fractionStatusDenominatorAsInt*
                                outputPowerNumeratorAsInt);
//cout << fractionStatusNumeratorAsInt << " " << fractionStatusDenominatorAsInt << endl;

this->initialNumerator=
helping_tools_1.convertIntToString(fractionStatusNumeratorAsInt);
this->initialDenominator=
helping_tools_1.convertIntToString(fractionStatusDenominatorAsInt);

/*stringstream ss1, ss2;
ss1<<fractionStatusNumeratorAsInt;
this->initialNumerator=ss1.str();
ss2<<fractionStatusDenominatorAsInt;
this->initialDenominator=ss2.str();*/
}

int constantPart::getFractionStatus()
{
    return fractionStatus;
}

void constantPart::setOutputPowerNumerator(string outputPowerNumerator)
{
    this->outputPowerNumerator=outputPowerNumerator;
    //cout << outputPowerNumerator << endl;
}

void constantPart::setOutputPowerDenominator(string outputPowerDenominator)
{
    this->outputPowerDenominator=outputPowerDenominator;
    //cout << outputPowerDenominator << endl;
}

void constantPart::parseFractionConstant(string constantStringAsInput)
{
    int i;
    for(i=0;i<constantStringAsInput.length();i++)
    {
        if(constantStringAsInput[i]=='(')
        {
            continue;
        }

        else if(constantStringAsInput[i]=='/')
        {
            break;
        }

        else
        {
            initialNumerator=initialNumerator+constantStringAsInput[i];
        }
    }
    i++;

    for(;i<constantStringAsInput.length();i++)
    {
        if(constantStringAsInput[i]==')')
        {
            break;
        }
        initialDenominator=initialDenominator+constantStringAsInput[i];
    }
}

void constantPart::setFunctionType(int functionTypeCode)
{
    this->functionType=functionTypeCode;
}

void constantPart::computeOutputConstantForFunctionTypeTwo()
{
    if(!constantStringAsInput.empty())
    outputConstant=outputConstant+"("+constantStringAsInput+")";
    //cout << outputConstant << endl;
}

void constantPart::computeOutputConstantForFunctionTypeThree()
{
    computeOutputConstantForFunctionTypeOne();
}

void constantPart::computeOutputConstantForFunctionTypeFour()
{
    computeOutputConstantForFunctionTypeOne();
}

void constantPart::computeOutputConstantForFunctionTypeFive()
{
    computeOutputConstantForFunctionTypeOne();
}

void constantPart::computeOutputConstantForFunctionTypeSix()
{
    computeOutputConstantForFunctionTypeOne();
}

void constantPart:: computeOutputConstantForFunctionTypeSeven()
{
    computeOutputConstantForFunctionTypeOne();
}

void constantPart::computeOutputConstantForFunctionTypeEight()
{
    computeOutputConstantForFunctionTypeOne();
}

void constantPart::computeOutputConstantForFunctionTypeNine()
{
    computeOutputConstantForFunctionTypeOne();
}

void constantPart::computeOutputConstantForFunctionTypeTen()
{
    //cout << isRootValueOfPowerNumerator << " " << isRootValueOfPowerDenominator << "\n";
    //cout << outputPowerNumerator << " " << outputPowerDenominator << "\n";
    if(!isRootValueOfPowerNumerator && !isRootValueOfPowerDenominator)
    {
        if(functionType==12 || functionType==13)
        outputPowerNumerator=helping_tools_1.multiplyStrings(outputPowerNumerator, "2");
        computeOutputConstantForFunctionTypeOne();
    }

    else
    {
        int emptyflag=0;
        if(functionType==12 || functionType==13)
        {
            if(constantStringAsInput=="" || constantStringAsInput.empty())
            { constantStringAsInput="1/2"; fractionStatus=1; emptyflag=1; }

        }
        //cout << constantStringAsInput << "\n";

        if(constantStringAsInput=="" || constantStringAsInput.empty())
        {
            outputConstant=outputConstant+"(" + outputPowerDenominator +"/"+
                            outputPowerNumerator + ")";
        }

        else
        {

            if(fractionStatus==0)  //Calculation when constant part is not a fraction
            {
                initialNumerator=constantStringAsInput;
                if(functionType==12 || functionType==13)
                initialDenominator="2";
                else
                initialDenominator="1";
            }

            else
            {
                parseFractionConstant(constantStringAsInput);
                if(!emptyflag && functionType!=10) initialDenominator=helping_tools_1.multiplyStrings
                    (initialDenominator, "2");
            }

            //cout << initialNumerator << " " << initialDenominator << "\n";
            helping_tools_1.numeratorDenominatorSimplification(initialNumerator, initialDenominator);

            if(!isRootValueOfPowerDenominator)
            helping_tools_1.numeratorDenominatorSimplification
            (outputPowerDenominator, initialDenominator);

            if(!isRootValueOfPowerNumerator)
            helping_tools_1.numeratorDenominatorSimplification
            (outputPowerNumerator, initialNumerator);

            if(!isRootValueOfPowerDenominator) {
            initialNumerator=helping_tools_1.multiplyStrings
            (initialNumerator, outputPowerDenominator);
            }

            else
            {
                if(initialNumerator!="1" && outputPowerDenominator!="1")
                initialNumerator="(" + initialNumerator + "*" + outputPowerDenominator + ")";

                else if(outputPowerDenominator!="1")
                initialNumerator="(" + outputPowerDenominator + ")";
            }

            if(!isRootValueOfPowerNumerator)
            {
            initialDenominator=helping_tools_1.multiplyStrings
            (initialDenominator, outputPowerNumerator);
            }

            else
            {
                if(initialDenominator!="1" && outputPowerNumerator!="1")
                initialDenominator="(" + initialDenominator + "*" + outputPowerNumerator + ")";

                else if(outputPowerNumerator!="1")
                initialDenominator="(" + outputPowerNumerator + ")";
            }

            //cout << initialNumerator << " " << initialDenominator << "\n";

            outputConstant="(" + initialNumerator;
            if(initialDenominator!="1")
            outputConstant=outputConstant+"/" + initialDenominator;

            outputConstant=outputConstant + ")";

        }
    }
}


void constantPart::computeOutputConstantForFunctionTypeTwelve()
{
    computeOutputConstantForFunctionTypeTen();
}


void constantPart::setIsRootValueOfPowerNumerator(int isRootValueOfPowerNumerator)
{
    this->isRootValueOfPowerNumerator=isRootValueOfPowerNumerator;
}

void constantPart::setIsRootValueOfPowerDenominator(int isRootValueOfPowerDenominator)
{
    this->isRootValueOfPowerDenominator=isRootValueOfPowerDenominator;
}
