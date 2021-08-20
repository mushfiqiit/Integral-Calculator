#include <bits/stdc++.h>
#include "term.h"

using namespace std;

term::term() // 1
{

}

void term::setTerm(string seperatedTerm) // 2
{
    this->recievedTerm = seperatedTerm;
    //cout << recievedTerm << "\n";

    int variableFunctionType=variable_Function_Part_TypeB_1.getfunctionType(recievedTerm);
    //cout << variableFunctionType << "\n";
    setTermFunctionType(variableFunctionType);
    if(variableFunctionType==0)
    termProcessorForTypeA();

    else
    {
        setTermFunctionType(variableFunctionType);
        termProcessorForTypeB();
    }
}

string term::getInitialTerm() // 3
{
    return recievedTerm;
}

constantPart term::getConstantPart() // 4
{
    return constant_Part_1;
}

variableFunctionPart term::getVariableFunctionPart() // 5
{
    return variable_Function_Part_1;
}

powerPart term::getPowerPart() // 6
{
    return power_Part_1;
}

void term::formOutputTerm() // 7
{
    if(functionType>=1 && functionType<=9 || functionType==-1)
    computeOutputTermForTypeA();

    else
    computeOutputTermForTypeB();
}

string term::getOutputTerm() // 8
{
    return outputTerm;
}

void term::termProcessorForTypeA() // 9
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
        if(recievedTerm[i]=='^' && functionType!="sec" && functionType!="cosec")
        {
            break;
        }

        else
        {
            functionType=functionType+recievedTerm[i];
        }
    }


    /*if(functionType.empty())
    {
        functionType="x";
    }*/

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
        power="0"; functionType="x";
    }
    // *******************
    //cout << constant << " " << functionType << " " << power << "\n";
    identifyFunctionType(constant, functionType, power);

    //cout << constant << " " << functionType << " " << power << "\n";

    constant_Part_1.setConstant(constant);
    variable_Function_Part_1.setVariableFunctionAsInput(functionType);
    power_Part_1.setInputPower(power);
}

void term::termProcessorForTypeB() // 10
{
    string tempConstantPartAsString=variable_Function_Part_TypeB_1.getConstantPart();
    tempConstantPartAsString=helping_tools_1.removeBrackets(tempConstantPartAsString);
    constant_Part_1.setConstant(tempConstantPartAsString);
    //cout << tempConstantPartAsString << "\n";
    for(int i=0;i<tempConstantPartAsString.length();i++)
    {
        if(tempConstantPartAsString[i]=='/') constant_Part_1.setFractionStatus(1);
    }
}

void term::computeOutputTermForTypeA() // 11
{
    power_Part_1.formOutputPower();
    //constant_Part_1.formOutputConstant(power_Part_1.getInputPower());

    //cout << "here \n";
    //cout << functionType << "\n";

    if(functionType==1 || functionType==2 || functionType==9)
    {
        //cout << power_Part_1.getFractionStatus() << " "
        //<< power_Part_1.getOutputPower() << "\n";
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
    //cout << "here \n";
    //Combine everything to from outputTerm
        outputTerm=outputTerm+constant_Part_1.getOutputConstant()+
                variable_Function_Part_1.getOutputVariableFunction();

                if(functionType==1 || functionType==9)
                {
                outputTerm=outputTerm+"^";
                }

        outputTerm=outputTerm+power_Part_1.getOutputPowerWithX();
    //****************************************
    }

    else if(functionType==3 || functionType==4 || functionType==5
     || functionType==6 || functionType==7 || functionType==8)
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
            //cout << "Here" << endl;
            constant_Part_1.formOutputConstant();
            variable_Function_Part_1.formOutputVariableFunction();

            //cout << constant_Part_1.getOutputConstant() << endl;
            outputTerm=outputTerm+constant_Part_1.getOutputConstant()
                 +variable_Function_Part_1.getOutputVariableFunction();
    }

    else if(functionType==-1) outputTerm= "Invalid Input";
}

void term::computeOutputTermForTypeB()
{
    variable_Function_Part_TypeB_1.formVariableFunctionAsOutput();
    constant_Part_1.setOutputPowerNumerator
    (variable_Function_Part_TypeB_1.getValueOfaNumerator());
    if(!variable_Function_Part_TypeB_1.getValueOfaDenominator().empty())
    constant_Part_1.setOutputPowerDenominator
    (variable_Function_Part_TypeB_1.getValueOfaDenominator());
    else
    constant_Part_1.setOutputPowerDenominator("1");

    constant_Part_1.setIsRootValueOfPowerNumerator
    (variable_Function_Part_TypeB_1.getIsRootValueOfaNumerator());
    constant_Part_1.setIsRootValueOfPowerDenominator
    (variable_Function_Part_TypeB_1.getIsRootValueOfaDenominator());

    constant_Part_1.formOutputConstant();

    //cout << variable_Function_Part_TypeB_1.getValueOfaNumerator() << " " <<
        //variable_Function_Part_TypeB_1.getValueOfaDenominator() << "\n";

    outputTerm=outputTerm+constant_Part_1.getOutputConstant()
                +variable_Function_Part_TypeB_1.getVariableFunctionAsOutput();
}


void term::identifyFunctionType(string constant, string variableFunction, string power) // 12
{
    //cout << variableFunction << "\n";
    string croppedvariableFunction;
    for(int i=0;i<variableFunction.length();i++)
    {
        if((variableFunction[i]>='a' && variableFunction[i]<='z') || (variableFunction[i]=='2'
                                            && variableFunction[i-1]=='^') || variableFunction[i]=='^')
           {
               croppedvariableFunction=croppedvariableFunction+variableFunction[i];
           }
    }
    //cout << constant << " " << croppedvariableFunction << " " << power << "\n";
    if(power=="-1")
    {
        setTermFunctionType(2);
    }

    else if(croppedvariableFunction=="sinx")
    {
        setTermFunctionType(3);
    }

    else if(croppedvariableFunction=="secxtanx")
    {
        setTermFunctionType(7);
    }

    else if(croppedvariableFunction=="cosecxcotx")
    {
        setTermFunctionType(8);
    }

    else if(croppedvariableFunction=="cosec^2x")
    {
        //cout << "HESE\n";
        setTermFunctionType(6);
    }


    else if(croppedvariableFunction=="cosx")
    {
        setTermFunctionType(4);
    }

    else if(croppedvariableFunction=="sec^2x")
    {
        //cout << "Here" << endl;
        setTermFunctionType(5);
    }

    else if(croppedvariableFunction=="x")
    {
        setTermFunctionType(1);
    }

    else if(croppedvariableFunction=="e")
    {
        setTermFunctionType(9);
    }

    else
    {
        setTermFunctionType(-1);
    }
    //cout << functionType << "\n";
}

void term::setTermFunctionType(int functionTypeCode) // 13
{
    //cout << functionTypeCode << endl;
    this->functionType=functionTypeCode;
    constant_Part_1.setFunctionType(functionTypeCode);
    variable_Function_Part_1.setFunctionType(functionTypeCode);
    power_Part_1.setFunctionType(functionTypeCode);
}
