#include <bits/stdc++.h>
#include "term.h"

using namespace std;

term::term()
{

}

void term::setTerm(string seperatedTerm)
{
    this->recievedTerm = seperatedTerm;
    termProcessor();
}

string term::getInitialTerm()
{
    return recievedTerm;
}

void term::termProcessor()
{
    string constant;
    string functionType;
    string power;
    int i;

    // Parsing constant part
    for(i=0;i<recievedTerm.size();i++)
    {
        if((recievedTerm[i]>='0' && recievedTerm[i]<='9') || recievedTerm[i]=='-')
        {
            constant=constant+recievedTerm[i];
        }

        else if(recievedTerm[i]=='/')

        {
            constant_Part_1.setFractionStatus(1);
            constant=constant+recievedTerm[i];
        }

        else if(recievedTerm[i]=='(' || recievedTerm[i]==')' || recievedTerm[i]==' '
                || recievedTerm[i]=='*')
        {
            continue;
        }

        else
        {
            break;
        }
    }
    // ********

    //Parsing variable function part
    for(;i<recievedTerm.size();i++)
    {
        if(recievedTerm[i]=='^')
        {
            break;
        }

        else
        {
            functionType=functionType+recievedTerm[i];
        }
    }


    if(functionType.empty())
    {
        functionType="x";
    }

    // ************


    // Parsing power part
    for(;i<recievedTerm.size();i++)
    {
        if(recievedTerm[i]=='/')
        {
            power_Part_1.setFractionStatus(1);
        }

        else if(recievedTerm[i]=='(' || recievedTerm[i]==')')
        {
            continue;
        }

        if(recievedTerm[i]!='^')
        {
        power=power+recievedTerm[i];
        }
    }


    if(power.empty() && functionType=="x")
    {
        power="1";
    }

    else if(power.empty() && functionType.empty())
    {
        power="0";
    }
    // *******************

    identifyFunctionType(constant, functionType, power);

    constant_Part_1.setConstant(constant);
    variable_Function_Part_1.setVariableFunctionAsInput(functionType);
    power_Part_1.setInputPower(power);
}

void term::computeOutputTerm()
{
    power_Part_1.formOutputPower();
    //constant_Part_1.formOutputConstant(power_Part_1.getInputPower());



    if(functionType==1 || functionType==2)
    {
        if(power_Part_1.getFractionStatus()==0)
        {
            constant_Part_1.setOutputPowerNumerator(power_Part_1.getOutputPower());
        }

        else
        {
            constant_Part_1.setOutputPowerNumerator(power_Part_1.getNumeratorAsOutput());
        }

    // If the power is not a fraction then denominator is 1
        if(power_Part_1.getFractionStatus()==0)
        {
            constant_Part_1.setOutputPowerDenominator("1");
        }

        else
        {
            constant_Part_1.setOutputPowerDenominator(power_Part_1.getDenominatorAsOutput());
        }
    //**********************************

        // Finally Compute constant
        constant_Part_1.formOutputConstant();
        //***************************

        //Compute output variable function
        variable_Function_Part_1.formOutputVariableFunction();
    //****************************

    //Combine everything to from outputTerm
        outputTerm=outputTerm+constant_Part_1.getOutputConstant()+
                variable_Function_Part_1.getOutputVariableFunction();

                if(functionType==1)
                {
                outputTerm=outputTerm+"^";
                }

        outputTerm=outputTerm+power_Part_1.getOutputPower();
    //****************************************
    }

    else if(functionType==3)
    {
        /*cout << constant_Part_1.getConstantStringAsInput() << " "
            << variable_Function_Part_1.getVariableFunctionAsInput() << " "
            << variable_Function_Part_1.getCoefficientStringAsInput() << endl; */
            if(variable_Function_Part_1.getCoefficientFractionStatus()==0)
            {
                constant_Part_1.setOutputPowerNumerator
                        (variable_Function_Part_1.getCoefficientStringAsInput());
                constant_Part_1.setOutputPowerDenominator
                        ("1");
                //cout << variable_Function_Part_1.getCoefficientStringAsInput() << endl;
            }

            else
            {
                constant_Part_1.setOutputPowerNumerator
                    (variable_Function_Part_1.getCoefficientNumerator());
                constant_Part_1.setOutputPowerDenominator
                    (variable_Function_Part_1.getCoefficientDenominator());
            }
            constant_Part_1.formOutputConstant();

            //cout << constant_Part_1.getOutputConstant() << endl;
            outputTerm=outputTerm+constant_Part_1.getOutputConstant();
    }
}

void term::formOutputTerm()
{
    computeOutputTerm();
}

constantPart term::getConstantPart()
{
    return constant_Part_1;
}

variableFunctionPart term::getVariableFunctionPart()
{
    return variable_Function_Part_1;
}

powerPart term::getPowerPart()
{
    return power_Part_1;
}

string term::getOutputTerm()
{
    return outputTerm;
}

void term::identifyFunctionType(string constant, string variableFunction, string power)
{
    if(power=="-1")
    {
        setTermFunctionType(2);
    }

    else if(variableFunction[0]=='s' && variableFunction[1]=='i' &&
            variableFunction[2]=='n')
    {
        setTermFunctionType(3);
    }

    else
    {
        setTermFunctionType(1);
    }
}

void term::setTermFunctionType(int functionTypeCode)
{
    //cout << functionTypeCode << endl;
    this->functionType=functionTypeCode;
    constant_Part_1.setFunctionType(functionTypeCode);
    variable_Function_Part_1.setFunctionType(functionTypeCode);
    power_Part_1.setFunctionType(functionTypeCode);
}
