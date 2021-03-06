#ifndef VARIABLEFUNCTIONPARTTYPEB_H
#define VARIABLEFUNCTIONPARTTYPEB_H
#include <bits/stdc++.h>
using namespace std;

class variableFunctionPartTypeB
{
    string variableFunctionAsInput;
    string parsedVariableFunctionAsInput();
    string constantPart;
    string valueOfa;
    bool isDigit(char ch);
    void parseVariableFunctionAsInput();

    public:
        variableFunctionPartTypeB();
        void setVariableFunctionPart(string variableFunctionAsInput);
};

#endif // VARIABLEFUNCTIONPARTTYPEB_H
