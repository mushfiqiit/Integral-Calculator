#include "coefficientpart.h"

Coefficientpart::Coefficientpart()
{
    //ctor
}

void Coefficientpart::setCoeffficientAsInput(string coefficentAsInput)
{
    this->coefficentAsInput=coefficentAsInput;

    if(fractionStatus==1)
    {
        int i;
        for(i=0;i<coefficentAsInput.length();i++)
        {
            if(coefficentAsInput[i]=='/')
            {
                i++;
                break;
            }

            else if(coefficentAsInput[i]=='(' || coefficentAsInput[i]==')')
            {
                continue;
            }

            else
            {
                coefficientNumerator=coefficientNumerator+coefficentAsInput[i];
            }
        }

        for(;i<coefficentAsInput.length();i++)
        {
            if(coefficentAsInput[i]=='(' || coefficentAsInput[i]==')')
            {
                continue;
            }

            else
            {
                coefficientDenominator=coefficientDenominator+coefficentAsInput[i];
            }
        }
    }
}

string Coefficientpart::getCoefficientAsInput()
{
    return this->coefficentAsInput;
}

void Coefficientpart::setFractionStatus(int fractionStatus)
{
    this->fractionStatus=fractionStatus;
}

int Coefficientpart::getFractionStatus()
{
    return this->fractionStatus;
}

string Coefficientpart::getCoefficientNumerator()
{
    return this->coefficientNumerator;
}

string Coefficientpart::getCoefficientDenominator()
{
    return this->coefficientDenominator;
}
