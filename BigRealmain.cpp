#include "iostream"
#include "bits//stdc++.h"
#include "string"
#include "Bigreal.cpp"
using namespace std;

int main()
{
    BigReal b("-5");
    BigReal br("10");
    br.validation();
    b.validation();
    cout<<b-br;//+17
    cout<<endl;
    cout<<br-b;//-17
    // cout<<br<<endl;
    // cout<<b;
    return 0;
}