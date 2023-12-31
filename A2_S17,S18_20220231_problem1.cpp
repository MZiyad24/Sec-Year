/*

 File: A2_S17,S18_20220231_problem1.cpp
 Purpose: correcting sentence's spacing and capitalization
 Author: Omar Mohammed Ahmed
 Section: S17, S18
 ID: 20220231
 TA: Dr.Rana Abdelkader
 Date: 2-November-2023

*/
//---------------------

#include <bits/stdc++.h>
using namespace std;
string correctcase(string input)
{
    if (isalpha(input[0]))
    {
        input[0] = toupper(input[0]);//convert first letter to upper case
    }
    for (int i = 1;i < input.size();i++)
    {
        if (isalpha(input[i])) {
            input[i] = tolower(input[i]);  //convert the rest to lower case
        }
    }
    return input;//return input string
}
string removeSpaces(string str)
{
    string target;
    int fspace = false;
    for (int i = 0;i < str.size();i++) {
        if (fspace && str[i] == ' ')continue;// If space is found for the first time,put one space in output
        fspace = (str[i] == ' ' ? true : false);//assign 1 if character is space else 0
        target += str[i];//
    }
    target += '.';
    return target;//return target string
}
int main() {
    string sentence;
    cout << "Enter the sentence less than or equal 100 chararcter==>\n";//input string
    getline(cin, sentence, '.');
    while (true) {
        if (sentence.length() > 100 || sentence == " " || sentence.empty()) {//check if sentence is valid or no
            cout << "Enter the correct sentence less than or equal 100 chararcter==>\n";
            getline(cin, sentence, '.');
        } else {
            sentence = removeSpaces(sentence);//remove spaces first
            cout << correctcase(sentence);//correct the case
            break;
        }
    }
}