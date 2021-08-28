#include <bits/stdc++.h>
#include "header1.h"
using namespace std;

int main()
{
    string recievedInput;
    term term_unit_1;
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t*****Integral Calculator*****\n\n";
    for(int i=0;i<6;i++) cout << "\t";
    for(int i=0;i<45;i++) cout << "-";
    cout << "\n\n";
    //Input taking
    while(1)
    {
        inputTakingUnit inputTakingUnit_1;
        if(!inputTakingUnit_1.takeInput()) break;
    }

    // **

    //recieve a term
   // term_unit_1.setTerm(inputTakingUnit_1.getProcessedTerm());

   /* temporaryConstant_1=term_unit_1.getConstantPart();
    temporary_Variable_Function_Part_1=term_unit_1.getVariableFunctionPart();
    temporary_Power_Part_1=term_unit_1.getPowerPart(); */

   // term_unit_1.formOutputTerm();

    return 0;
}
