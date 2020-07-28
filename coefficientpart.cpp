#include "coefficientpart.h"

Coefficientpart::Coefficientpart()
{
    fractionStatus=0;
}

void Coefficientpart::setCoeffficientAsInput(string coefficentAsInput)
{
    this->coefficentAsInput=coefficentAsInput;
    //cout << coefficentAsInput << endl;

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
    //cout << "Coefficient : " << this->coefficentAsInput << endl;
    if(this->coefficentAsInput.empty() || this->coefficentAsInput.length()==0 || this->coefficentAsInput=="()")
    {
        //cout << "Done " << endl;
        return "1";
    }
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
