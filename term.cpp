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

    // Parsing constant part
    for(int i=0;i<recievedTerm.size();i++)
    {
        if(recievedTerm[i]>='0' && recievedTerm[i]<='9')
        {
            constant=constant+recievedTerm[i];
        }

        else
        {
            break;
        }
    }
    constant_Part_1.setConstant(constant);

    //Parsing variable function part
    for(;i<recievedTerm.size();i++)
    {
        if(recievedTerm[i]!='^')
        {
            break;
        }

        else
        {
            functionType=functionType+recievedTerm[i];
        }
    }
    variable_Function_Part_1.setVariableFunctionAsInput(functionType);

    // Parsing power part

    for(i++;i<recievedTerm.size();i++)
    {
        power=power+recievedTerm[i];
    }

}

constantPart term::getConstantPart()
{
    return constant_Part_1;
}
