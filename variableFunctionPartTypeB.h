#ifndef VARIABLEFUNCTIONPARTTYPEB_H
#define VARIABLEFUNCTIONPARTTYPEB_H
#include <bits/stdc++.h>
#include "helpingtools.h"
using namespace std;

class variableFunctionPartTypeB
{
    string variableFunctionAsInput;
    string variableFunctionAsOutput;
    string constantPart;
    string constantPartNumerator; string constantPartDenominator;
    int variableFunctionType;
    string valueOfaSquare; int valueOfaSquareAsInt;
    string valueOfaSquareNumerator; string valueOfaSquareDenominator;
    int valueOfaSquareNumeratorAsInt; int valueOfaSquareDenominatorAsInt;
    string valueOfa; int valueOfaAsInt;
    string valueOfaNumerator; string valueOfaDenominator;
    int valueOfaNumeratorAsInt; int valueOfaDenominatorAsInt;

    int valueOfaFractionStatus;
    helpingtools helping_tools_1;


    bool isDigit(char ch);
    bool isPerfectSquare(int numberToCheck);
    string parseVariableFunctionAsInput(string variableFunctionToParse);
    int identifyFunctionTypeB(string variableFunctionToIdentify);
    void computeVariableFunctionAsOutput();
    void computeVariableFunctionAsOutputForFunctionTypeTen();
    string constantAndMainFunctionSeperation(string variableFunctionToSeperate);
    void valueOfaNumeratorDenominatorSeperation();
    void valueOfaNumeratorDenominatorCalculation();

    public:
        variableFunctionPartTypeB(); // 1
        void setVariableFunctionPart(string variableFunctionAsInput); // 2
        string getVariableFunctionAsInput();
        int getfunctionType(string variableFunctionToIdentify); //4
        string getVariableFunctionAsOutput();
        void setVariableFunctionType(int functionType);
        string getConstantPart();
        void formVariableFunctionAsOutput();
        string getValueOfaNumerator();
        string getValueOfaDenominator();

};

#endif // VARIABLEFUNCTIONPARTTYPEB_H
