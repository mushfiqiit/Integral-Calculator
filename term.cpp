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
        if(recievedTerm[i]>='0' && recievedTerm[i]<='9')
        {
            constant=constant+recievedTerm[i];
        }

      /*  else if(recievedTerm[i]=='/')
        {
            constant_Part_1.setFractionStatus(1);
        } */

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
        if(recievedTerm[i]!='^')
        {
        power=power+recievedTerm[i];
        }
    }

    power_Part_1.setInputPower(power);

    if(power.empty())
    {
        power_Part_1.setInputPower("1");
    }
    // *******
}

void term::computeOutputTerm()
{
    constant_Part_1.formOutputConstant(power_Part_1.getInputPower());
    power_Part_1.formOutputPower();
    outputTerm=outputTerm+constant_Part_1.getOutputConstant()+
                variable_Function_Part_1.getVariableFunctionAsInput()+
                "^" +
                power_Part_1.getOutputPower();
        cout << outputTerm << endl;
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
