#ifndef VARIABLEFUNCTIONPART_H
#define VARIABLEFUNCTIONPART_H
#include <bits/stdc++.h>

using namespace std;

class variableFunctionPart
{
    string variableFunctionAsInput;
    public:
        variableFunctionPart();
        void setVariableFunctionAsInput(string variableFunctionAsInput);
        string getVariableFunctionAsInput();
        bool functionIsX();
        bool functionIsEmpty();
};

#endif // VARIABLEFUNCTIONPART_H