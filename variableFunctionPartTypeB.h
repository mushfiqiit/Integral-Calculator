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
    int isRootValueOfaNumerator, isRootValueOfaDenominator;

    int valueOfaFractionStatus;
    helpingtools helping_tools_1;


    bool isDigit(char ch); // 11
    bool isPerfectSquare(int numberToCheck); // 12
    string parseVariableFunctionAsInput(string variableFunctionToParse); // 13
    int identifyFunctionTypeB(string variableFunctionToIdentify); // 14
    void computeVariableFunctionAsOutput(); // 15
    void computeVariableFunctionAsOutputForFunctionTypeTen(); // 16
    string constantAndMainFunctionSeperation(string variableFunctionToSeperate); // 17
    void valueOfaNumeratorDenominatorSeperation(); // 18
    void valueOfaNumeratorDenominatorCalculation(); // 19

    public:
        variableFunctionPartTypeB(); // 1
        void setVariableFunctionPart(string variableFunctionAsInput); // 2
        string getVariableFunctionAsInput(); // 3
        int getfunctionType(string variableFunctionToIdentify); //4
        string getVariableFunctionAsOutput();
        void setVariableFunctionType(int functionType); // 6
        string getConstantPart(); // 7
        void formVariableFunctionAsOutput(); // 8
        string getValueOfaNumerator(); // 9
        string getValueOfaDenominator(); // 10
        int getIsRootValueOfaNumerator();
        int getIsRootValueOfaDenominator();

};

#endif // VARIABLEFUNCTIONPARTTYPEB_H
