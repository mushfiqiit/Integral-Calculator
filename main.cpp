#include <bits/stdc++.h>
#include "header1.h"
using namespace std;

int main()
{
    term term_unit_1;
    constantPart temporaryConstant_1;

    //Input taking
    inputTakingUnit inputTakingUnit_1;
    inputTakingUnit_1.takeInput();
    // **

    //recieve a term
    term_unit_1.setTerm(inputTakingUnit_1.getProcessedTerm());

    temporaryConstant_1=term_unit_1.getConstantPart();

    cout << temporaryConstant_1.getConstantStringAsInput() << endl;


    return 0;
}
