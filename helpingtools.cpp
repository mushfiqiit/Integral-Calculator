#include "helpingtools.h"

helpingtools::helpingtools() // 1
{
    rootSign+=(char)(251);
    //ctor
}

bool helpingtools::isDigit(char ch) // 2
{
    if((ch>='0' && ch<='9')||ch=='/') return true;
    else return false;
}


bool helpingtools::isPerfectSquare(int numberToCheck) // 3
{
    if(sqrt(numberToCheck)*sqrt(numberToCheck)==numberToCheck) return true;
    else return false;
}

int helpingtools::convertStringToInt(string stringToConvert) // 4
{
    int convertedInt;
    convertedInt=atoi(stringToConvert.c_str());
    return convertedInt;
}

string helpingtools::convertIntToString(int intToConvert) // 5
{
    string convertedString;
    stringstream ss;
    ss<<intToConvert;
    convertedString=ss.str();
    return convertedString;
}

string helpingtools::removeBrackets(string stringToRemoveBrackets) // 6
{
    string result;
    for(int i=0;i<stringToRemoveBrackets.length();i++)
    {
        if(stringToRemoveBrackets[i]!=')' && stringToRemoveBrackets[i]!='(')
        {
            result=result+stringToRemoveBrackets[i];
        }
    }
    return result;
}

string helpingtools::multiplyStrings(string stringToMultiply_1, string stringToMultiply_2) // 7
{
    int intToMultiply_1=convertStringToInt(stringToMultiply_1);
    int intToMultiply_2=convertStringToInt(stringToMultiply_2);
    int resultAsInt=intToMultiply_1*intToMultiply_2;
    string result=convertIntToString(resultAsInt);
    return result;
}

string helpingtools::addRoot(string stringToAddRoot)
{
    string resultString;
    resultString= "(" + stringToAddRoot + "^(1/2))";
    return resultString;
}

void helpingtools::numeratorDenominatorSimplification(string& numerator, string& denominator)
{
    int numeratorAsInt=atoi(numerator.c_str());
    int denominatorAsInt=atoi(denominator.c_str());
    int numeratorAsIntFinal, denominatorAsIntFinal;
    //cout << numeratorAsInt << " " << denominatorAsInt << endl;

    numeratorAsIntFinal=numeratorAsInt/__gcd(numeratorAsInt, denominatorAsInt);
    denominatorAsIntFinal=denominatorAsInt/__gcd(numeratorAsInt, denominatorAsInt);

    if(numeratorAsIntFinal<0 && denominatorAsIntFinal<0)
    {
        numeratorAsIntFinal=abs(numeratorAsIntFinal);
        denominatorAsIntFinal=denominatorAsIntFinal;
    }

    else if((numeratorAsIntFinal<0 && denominatorAsIntFinal>0)||
            (numeratorAsIntFinal>0 && denominatorAsIntFinal<0))
    {
        if(numeratorAsIntFinal>0)
        {
            numeratorAsIntFinal=-numeratorAsIntFinal;
            denominatorAsIntFinal=abs(denominatorAsIntFinal);
        }
    }

    numerator=convertIntToString(numeratorAsIntFinal);

    denominator=convertIntToString(denominatorAsIntFinal);
}

string helpingtools::addRootSign(string stringToRoot)
{
    string resultString=(string)rootSign+"(" + stringToRoot + ") " ;
    //cout << rootSign << " " << resultString << "\n";
    return resultString;
}
