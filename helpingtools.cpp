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

long long int helpingtools::convertStringToInt(string stringToConvert) // 4
{
    long long int convertedInt=0;
    long long int stringLength=stringToConvert.length();
    int firstDigitCharacterIndex=0;
    int negativeFlag=0;

    //If the number is negative, ignore first character.
    if(stringToConvert[0]=='-')
    {
        firstDigitCharacterIndex=1;
        negativeFlag=1;
    }


    for(int iterator_i=stringLength-1;iterator_i>=firstDigitCharacterIndex;
    iterator_i--)
    {
        convertedInt=convertedInt*10;
        convertedInt+=(long long int)(stringToConvert[iterator_i]-'0');
    }

    if(negativeFlag)
    {
        convertedInt=-convertedInt;
    }
    //cout << stringToConvert << " " << convertedInt << "\n";
    return convertedInt;
}

string helpingtools::convertIntToString(long long int intToConvert) // 5
{
    string convertedString;
    string temporaryString;
    int negativeFlag=0;

    // If integer is negative
    if(intToConvert<0)
    {
        negativeFlag=1;
        intToConvert=-intToConvert;
    }
    while(intToConvert>0)
    {
        int lastDigit=intToConvert%10;
        temporaryString+=(char)(lastDigit+'0');
        intToConvert=intToConvert/10;
    }
    int temporaryStringLength=temporaryString.length();
    if(negativeFlag) convertedString+="-";
    for(int i=temporaryStringLength-1;i>=0;i--)
    {
        convertedString+=temporaryString[i];
    }
    //cout << intToConvert << "ab" << convertedString << "\n";
    //stringstream ss;
    //ss<<intToConvert;
    //convertedString=ss.str();
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
