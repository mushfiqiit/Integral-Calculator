#include "inputTakingUnit.h"
#include <bits/stdc++.h>

using namespace std;

inputTakingUnit::inputTakingUnit()
{

}

void inputTakingUnit::takeInput()
{
    cout << "Input : ";
    getline(cin, recievedInput);
    processInputToTerms();
}

void inputTakingUnit::processInputToTerms()
{
    string temporaryTerm;
    int termIterator=0;

    // Partitioning terms
    for(int i=0;i<recievedInput.size();i++)
    {

        if(recievedInput[i]==' ' && (recievedInput[i+1]=='+' || recievedInput[i+1]=='-') &&
           recievedInput[i+2]==' ')
        {
            i=i+2;
            termIterator++;
        }

        else{
        arrayOfTermStrings[termIterator]=arrayOfTermStrings[termIterator]+
                                    recievedInput[i];
        }


         //   temporaryTerm= temporaryTerm+recievedInput[i];
    }
   // processedToTerm=temporaryTerm;
   // ***********************

   for(int i=0;i<=termIterator;i++)
   {
       arrayOfTerms[i].setTerm(arrayOfTermStrings[i]);
       arrayOfTerms[i].formOutputTerm();
   }
   formOutputString(termIterator);
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

void inputTakingUnit::formOutputString(int termCount)
{
    string resultToShow;

    resultToShow=resultToShow+arrayOfTerms[0].getOutputTerm();

    for(int i=1; i<=termCount;i++)
    {
        resultToShow=resultToShow + " + ";
        resultToShow=resultToShow + arrayOfTerms[i].getOutputTerm();
    }
    outputUnit_1.setResultToShow(resultToShow);
    outputUnit_1.showOutput();
   // cout << resultToShow << endl;
}
