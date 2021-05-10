#ifndef HELPINGTOOLS_H
#define HELPINGTOOLS_H
#include <bits/stdc++.h>
using namespace std;

class helpingtools
{
    public:
        helpingtools(); // 1

        bool isDigit(char ch); // 2
        bool isPerfectSquare(int numberToCheck); // 3
        int convertStringToInt(string stringToConvert); // 4
        string convertIntToString(int intToConvert); // 5
        string removeBrackets(string stringToRemoveBrackets); // 6
        string multiplyStrings(string stringToMultiply_1,string stringToMultiply_2); // 7
        string addRoot(string stringToAddRoot);
        string numeratorDenominatorSimplification(string& string_a, string& string_2);
};

#endif // HELPINGTOOLS_H
