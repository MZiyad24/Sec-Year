#include "iostream"
#include "bits//stdc++.h"
#include "string"
#ifndef UNTITLED1_BIGREAL_H
#define UNTITLED1_BIGREAL_H
using namespace std;
class BigReal
{
private:
    char sign='+';
    string real_number;
    string integr="0",fraction="0";
public:
    BigReal(string real)
    {
        real_number=real;
    }
    void validation();
    string operator +(BigReal&bigreal);
    string operator-(BigReal&bigreal);
    bool operator >(BigReal&bigreal);
    bool operator <(BigReal&bigreal);
    bool operator ==(BigReal&bigreal);
    ostream  operator <<(ostream& output);
    friend ostream & operator <<(ostream &output ,BigReal &bigreal);
};


#endif //UNTITLED1_BIGREAL_H
