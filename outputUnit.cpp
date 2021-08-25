#include "outputUnit.h"
#include <bits/stdc++.h>

using namespace std;

outputUnit::outputUnit()
{
    //ctor
}

void outputUnit::showOutput()
{
    cout << "\tOutput : " <<  resultToShow << " + c" << "\n\n";
}

void outputUnit::setResultToShow(string resultToShow)
{
    this->resultToShow=resultToShow;
}
