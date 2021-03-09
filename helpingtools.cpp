#include "helpingtools.h"

helpingtools::helpingtools()
{
    //ctor
}

int helpingtools::convertStringToInt(string stringToConvert)
{
    int convertedInt;
    convertedInt=atoi(stringToConvert.c_str());
    return convertedInt;
}

string helpingtools::convertIntToString(int intToConvert)
{
    string convertedString;
    stringstream ss;
    ss<<intToConvert;
    convertedString=ss.str();
    return convertedString;
}
