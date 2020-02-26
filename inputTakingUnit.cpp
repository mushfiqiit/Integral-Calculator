#include "inputTakingUnit.h"
#include <bits/stdc++.h>

using namespace std;

inputTakingUnit::inputTakingUnit()
{

}

void inputTakingUnit::takeInput()
{
    cin >> recievedInput;
    processInputToTerms();
}

void inputTakingUnit::processInputToTerms()
{
    string temporaryTerm;

    for(int i=0;i<recievedInput.size();i++)
    {
            temporaryTerm= temporaryTerm+recievedInput[i];
    }
    processedToTerm=temporaryTerm;
}

string inputTakingUnit::getProcessedTerm()
{
    processInputToTerms();
    return processedToTerm;

}

string inputTakingUnit::getRecievedInput()
{
    return recievedInput;
}

