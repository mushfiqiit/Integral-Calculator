#ifndef VARIABLEFUNCTIONPART_H
#define VARIABLEFUNCTIONPART_H
#include <bits/stdc++.h>

using namespace std;

class variableFunctionPart
{
    string variableFunctionAsInput;
    int functionType;
    public:
        variableFunctionPart();
        void setVariableFunctionAsInput(string variableFunctionAsInput);
        string getVariableFunctionAsInput();
        bool functionIsX();
        bool functionIsEmpty();
        void setFunctionType(int functionTypeCode);
};

#endif // VARIABLEFUNCTIONPART_H
