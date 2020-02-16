#include <bits/stdc++.h>
#include "header1.h"
using namespace std;

int main()
{
    term term_unit_1;
    constantPart temporaryConstant_1;
    variableFunctionPart temporary_Variable_Function_Part_1;
    powerPart temporary_Power_Part_1;

    //Input taking
    inputTakingUnit inputTakingUnit_1;
    inputTakingUnit_1.takeInput();
    // **

    //recieve a term
    term_unit_1.setTerm(inputTakingUnit_1.getProcessedTerm());

    temporaryConstant_1=term_unit_1.getConstantPart();
    temporary_Variable_Function_Part_1=term_unit_1.getVariableFunctionPart();
    temporary_Power_Part_1=term_unit_1.getPowerPart();

    cout << temporaryConstant_1.getConstantStringAsInput() << endl;
    cout << temporary_Variable_Function_Part_1.getVariableFunctionAsInput() << endl;
    cout << temporary_Power_Part_1.getInputPower() << endl;


    return 0;
}
