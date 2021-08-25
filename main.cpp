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

    while(recievedInput!="quit")
    {
        cout << "\n\n\tInput : ";
        getline(cin, recievedInput);
        cout << "\n\n";
        if(recievedInput=="quit")
        {
            cout << "Thank you for using our Integral Calculator\n\n";
            break;
        }
        if(recievedInput.empty())
        {
            cout << "\t\tPlease try again.\n\n"; continue;
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
