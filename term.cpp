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
    constant_Part_1.setConstant(constant);
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
    variable_Function_Part_1.setVariableFunctionAsInput(functionType);


    if(functionType.empty())
    {
        variable_Function_Part_1.setVariableFunctionAsInput("x");
    }

    // ************


    // Parsing power part
    for(;i<recievedTerm.size();i++)
    {
        if(recievedTerm[i]=='/')
        {
            power_Part_1.setFractionStatus(1);
        }

        if(recievedTerm[i]!='^')
        {
        power=power+recievedTerm[i];
        }
    }

    power_Part_1.setInputPower(power);

    if(power.empty() && functionType=="x")
    {
        power_Part_1.setInputPower("1");
    }

    else if(power.empty() && functionType.empty())
    {
        power_Part_1.setInputPower("0");
    }
    // *******************

    identifyFunctionType(constant, functionType, power);
}

void term::computeOutputTerm()
{
    power_Part_1.formOutputPower();
    //constant_Part_1.formOutputConstant(power_Part_1.getInputPower());

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

    //Combine everything to from outputTerm
    outputTerm=outputTerm+constant_Part_1.getOutputConstant()+
                variable_Function_Part_1.getVariableFunctionAsInput()+
                "^" +
                power_Part_1.getOutputPower();
    //****************************************

     //   cout << "Output : " << outputTerm << endl;
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

    else
    {
        setTermFunctionType(1);
    }
}

void term::setTermFunctionType(int functionTypeCode)
{
    this->functionType=functionTypeCode;
}
