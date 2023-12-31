/*

 File: A2_S17,S18_20220231_problem3.cpp
 Purpose: splitting the sentence by a given delimiter
 Author: Omar Mohammed Ahmed
 Section: S17, S18
 ID: 20220231
 TA: Dr.Rana Abdelkader
 Date: 1-November-2023

*/
//---------------------

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &target, char delimiter) { // splitting function
    vector<string> result;  // the splited version
    istringstream iss(target);
    string token;

    while (getline(iss, token, delimiter))
        result.push_back(token);

    return result;
}

int main() {
    string input1;
    char delimiter;

    cout << "Enter the first string to split: ";
    getline(cin, input1);

    cout << "Enter the delimiter: ";
    cin >> delimiter;

    vector<string> result1 = split(input1, delimiter);

    cout << endl;
    for (const auto& str : result1) {  // itterating over the result
        cout << str << endl;
    }

    return 0;
}
