#include <bits/stdc++.h>
#include "header1.h"
using namespace std;

int main()
{
    term term_unit_1;

    //Input taking
    inputTakingUnit inputTakingUnit_1;
    inputTakingUnit_1.takeInput();
    // **

    //recieve a term
    term_unit_1.setTerm(inputTakingUnit_1.getProcessedTerm());


    cout << inputTakingUnit_1.getProcessedTerm() << endl;


    return 0;
}
