#include <bits/stdc++.h>
#include "header1.h"
using namespace std;

int main()
{
    string recievedInput;
    term term_unit_1;

    cout << "\tInput Instructions : \n\n";
    cout << "\t1. Two terms must be seperated from their operators by a space.\n\n";
    cout << "\t2. The constant must be a nonzero integer or fraction.\n\n";
    cout << "\t3. The power must be a nonzero integer. \n\n";
    cout << "\t4. Do not use empty input.\n\n";
    cout << "\t4. Enter quit to exit.\n\n";
    cout << "\t Sample Input : (7/3)x^2. \n\n";


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
