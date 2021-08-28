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
    cout << "Please use any of the following format as input function :\n\n";
    cout << "Function type 1 : ax^n\n\n";
    cout << "Function type 2 : ax^(-1)\n\n";
    cout << "Function type 3 : a sin (px/q) or a sin mx\n\n";
    cout << "Function type 4 : a cos (px/q) or a cos mx\n\n";
    cout << "Function type 5 : a sec^2 (px/q) or a sec^2 (mx) \n\n";
    cout << "Function type 6 : a cosec^2 (px/q) or a cosec^2 (mx) \n\n";
    cout << "Function type 7 : a sec(px/q) tan (px/q) or a sec (mx) tan (mx) \n\n";
    cout << "Function type 8 : a cosec(px/q) cot(px/q) or a cosec(mx) cot(mx) \n\n";
    cout << "Function type 9 : a e^(mx) or a e^(px/q)\n\n";
    cout << "Function type 10 : (a)(1/((m)+x^2) ) \n\n";
    cout << "Function type 11 : (a) (1/( ((m)-x^2)^(1/2) ) \n\n";
    cout << "Function type 12 : (a) (1/( (m)-x^2) ) \n\n";
    cout << "Function type 13 : (a) (1/(x^2- (m) ) ) \n\n";
    cout << "Notes : a can be fraction or integer.\n\n \t" ;
    cout << "m can be a fraction for function types 10 to 13. Otherwise integer. \n\n";
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
