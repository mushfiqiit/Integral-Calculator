#include <bits/stdc++.h>
#include "term.h"

using namespace std;

term::term()
{

}

void term::setTerm(string seperatedTerm)
{
    this->recievedTerm = seperatedTerm;
}

string term::getInitialTerm()
{
    return recievedTerm;
}
