#ifndef VARIABLEFUNCTIONPARTTYPEB_H
#define VARIABLEFUNCTIONPARTTYPEB_H
#include <bits/stdc++.h>
using namespace std;

class variableFunctionPartTypeB
{
    string variableFunctionAsInput;
    string variableFunctionAsOutput;
    string constantPart;
    string constantPartNumerator; string constantPartDenominator;
    int variableFunctionType;
    string valueOfaSquare; int valueOfaSquareAsInt;
    string valueOfa; int valueOfaAsInt;


    bool isDigit(char ch);
    bool isPerfectSquare(int numberToCheck);
    string parseVariableFunctionAsInput(string variableFunctionToParse);
    int identifyFunctionTypeB(string variableFunctionToIdentify);
    void computeVariableFunctionAsOutput();
    void computeVariableFunctionAsOutputForFunctionTypeTen();

    public:
        variableFunctionPartTypeB(); // 1
        void setVariableFunctionPart(string variableFunctionAsInput); // 2
        string getVariableFunctionAsInput();
        int getfunctionType(string variableFunctionToIdentify); //4
        string getVariableFunctionAsOutput();
        void setVariableFunctionType(int functionType);
        string getConstantPart();
        void formVariableFunctionAsOutput();

};

#endif // VARIABLEFUNCTIONPARTTYPEB_H
