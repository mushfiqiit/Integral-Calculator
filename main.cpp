#include <bits/stdc++.h>
#include "header1.h"
using namespace std;

int main()
{
    string recievedInput;
    term term_unit_1;


    //Input taking

    while(recievedInput!="quit")
    {
        cout << "Input : ";
        getline(cin, recievedInput);
        cout << "\n\n";
        if(recievedInput=="quit")
        {
            break;
        }
    inputTakingUnit inputTakingUnit_1;
    inputTakingUnit_1.takeInput(recievedInput);
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
