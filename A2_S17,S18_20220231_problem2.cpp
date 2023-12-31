/*

 File: A2_S17,S18_20221093_problem2.cpp
 Purpose: converting male speech into both men and women speech
 Author: Omar Mohammed Ahmed
 Section: S17, S18
 ID: 20220231
 TA: Dr.Rana Abdelkader
 Date: 2-November-2023

*/
//---------------------

#include <iostream>
#include <string>

using namespace std;

void first_word(string& str){
    // he options.......
    string he1 = "he ";
    string he2 = "He ";
    string he3 = "HE ";
    // his options......
    string his1 = "his ";
    string his2 = "His ";
    string his3 = "HIS ";
    // him options......
    string him1 = "him ";
    string him2 = "Him ";
    string him3 = "HIM ";

    string neu;
    int pos = 0;

    // He or she........
    if (he1[0] == str[0] && he1[1] == str[1] && he1[2] == str[2]){
        neu = "he or she ";
        str.replace(pos, he1.length(), neu);
    }
    else if (he2[0] == str[0] && he2[1] == str[1] && he2[2] == str[2]){
        neu = "He or She ";
        str.replace(pos, he2.length(), neu);
    }
    else if (he3[0] == str[0] && he3[1] == str[1] && he3[2] == str[2]){
        neu = "HE OR SHE ";
        str.replace(pos, he3.length(), neu);
    }

    // His or her........
    if (his1[0] == str[0] && his1[1] == str[1] && his1[2] == str[2]){
        neu = "his or her ";
        str.replace(pos, his1.length(), neu);
    }
    else if (his2[0] == str[0] && his2[1] == str[1] && his2[2] == str[2]){
        neu = "His or Her ";
        str.replace(pos, his2.length(), neu);
    }
    else if (his3[0] == str[0] && his3[1] == str[1] && his3[2] == str[2]){
        neu = "HIS OR HER ";
        str.replace(pos, his3.length(), neu);
    }

    // Him or her........
    if (him1[0] == str[0] && him1[1] == str[1] && him1[2] == str[2]){
        neu = "him or her ";
        str.replace(pos, him1.length(), neu);
    }
    else if (him2[0] == str[0] && him2[1] == str[1] && him2[2] == str[2]){
        neu = "Him or Her ";
        str.replace(pos, him2.length(), neu);
    }
    else if (him3[0] == str[0] && him3[1] == str[1] && him3[2] == str[2]){
        neu = "HIM OR HER ";
        str.replace(pos, him3.length(), neu);
    }
}

void mid_word(string& str){
    // he option.......
    string he1 = " he ", neu1 = " he or she ";
    string he2 = " He ", neu2 = " He or She ";
    string he3 = " HE ", neu3 = " HE OR SHE ";
    // his options......
    string his1 = " his ", neu4 = " his or her ";
    string his2 = " His ", neu5 = " His or Her ";
    string his3 = " HIS ", neu6 = " HIS OR HER ";
    // him options......
    string him1 = " him ", neu7 = " him or her ";
    string him2 = " Him ", neu8 = " Him or Her ";
    string him3 = " HIM ", neu9 = " HIM OR HER ";

    int pos;

    // he options.......
    pos = 2;
    while ((pos = str.find(he1, pos)) != std::string::npos) {
        str.replace(pos, he1.length(), neu1);
        pos += neu1.length();

    }
    pos = 2;
    while ((pos = str.find(he2, pos)) != std::string::npos) {
        str.replace(pos, he2.length(), neu2);
        pos += neu2.length();
    }
    pos = 2;
    while ((pos = str.find(he3, pos)) != std::string::npos) {
        str.replace(pos, he3.length(), neu3);
        pos += neu3.length();
    }

    // his options.......
    pos = 3;
    while ((pos = str.find(his1, pos)) != std::string::npos) {
        str.replace(pos, his1.length(), neu4);
        pos += neu4.length();

    }
    pos = 3;
    while ((pos = str.find(his2, pos)) != std::string::npos) {
        str.replace(pos, his2.length(), neu5);
        pos += neu5.length();
    }
    pos = 3;
    while ((pos = str.find(his3, pos)) != std::string::npos) {
        str.replace(pos, his3.length(), neu6);
        pos += neu6.length();
    }

    // him options.......
    pos = 3;
    while ((pos = str.find(him1, pos)) != std::string::npos) {
        str.replace(pos, him1.length(), neu7);
        pos += neu7.length();

    }
    pos = 3;
    while ((pos = str.find(him2, pos)) != std::string::npos) {
        str.replace(pos, him2.length(), neu8);
        pos += neu8.length();
    }
    pos = 3;
    while ((pos = str.find(him3, pos)) != std::string::npos) {
        str.replace(pos, him3.length(), neu9);
        pos += neu9.length();
    }
}

void symbols_word(string& str){
    // he options.......
    string he1 = " he.", he2 = " he,", he3 = ",he ";
    string neu1 = " he or she.", neu2 = " he or she,", neu3 = ",he or she ";
    string he4 = " He.", he5 = " He,", he6 = ",He ";
    string neu4 = " He or She.", neu5 = " He or She,", neu6 = ",He or She ";
    string he7 = " HE.", he8 = " HE,", he9 = ",HE ";
    string neu7 = " HE OR SHE.", neu8 = " HE OR SHE,", neu9 = ",HE OR SHE ";

    // his options......
    string his1 = " his.", his2 = " his,", his3 = ",his ";
    string neu10 = " his or her.", neu11 = " his or her,", neu12 = ",his or her ";
    string his4 = " His.", his5 = " His,", his6 = ",His ";
    string neu13 = " His or Her.", neu14 = " His or Her,", neu15 = ",His or Her ";
    string his7 = " HIS.", his8 = " HIS,", his9 = ",HIS ";
    string neu16 = " HIS OR HIS.", neu17 = " HIS OR HER,", neu18 = ",HIS OR HER ";

    // him options......
    string him1 = " him.", him2 = " him,", him3 = ",him ";
    string neu19 = " him or her.", neu20 = " him or her,", neu21 = ",him or her ";
    string him4 = " Him.", him5 = " Him,", him6 = ",Him ";
    string neu22 = " Him or Her.", neu23 = " Him or Her,", neu24 = ",Him or Her ";
    string him7 = " HIM.", him8 = " HIM,", him9 = ",HIM ";
    string neu25 = " HIM OR HER.", neu26 = " HIM OR HER,", neu27 = ",HIM OR HER ";

    int pos;



    // he option........................................................................
    pos = 2;
    while ((pos = str.find(he1, pos)) != std::string::npos) {
        str.replace(pos, he1.length(), neu1);
        pos += neu1.length();

    }
    pos = 2;
    while ((pos = str.find(he2, pos)) != std::string::npos) {
        str.replace(pos, he2.length(), neu2);
        pos += neu2.length();
    }
    pos = 2;
    while ((pos = str.find(he3, pos)) != std::string::npos) {
        str.replace(pos, he3.length(), neu3);
        pos += neu3.length();
    }
    pos = 2;
    while ((pos = str.find(he4, pos)) != std::string::npos) {
        str.replace(pos, he4.length(), neu4);
        pos += neu4.length();

    }
    pos = 2;
    while ((pos = str.find(he5, pos)) != std::string::npos) {
        str.replace(pos, he5.length(), neu5);
        pos += neu5.length();
    }
    pos = 2;
    while ((pos = str.find(he6, pos)) != std::string::npos) {
        str.replace(pos, he6.length(), neu6);
        pos += neu6.length();
    }
    pos = 2;
    while ((pos = str.find(he7, pos)) != std::string::npos) {
        str.replace(pos, he7.length(), neu7);
        pos += neu7.length();

    }
    pos = 2;
    while ((pos = str.find(he8, pos)) != std::string::npos) {
        str.replace(pos, he8.length(), neu8);
        pos += neu8.length();
    }
    pos = 2;
    while ((pos = str.find(he9, pos)) != std::string::npos) {
        str.replace(pos, he9.length(), neu9);
        pos += neu9.length();
    }

    // his options.......................................................................
    pos = 3;
    while ((pos = str.find(his1, pos)) != std::string::npos) {
        str.replace(pos, his1.length(), neu10);
        pos += neu10.length();

    }
    pos = 3;
    while ((pos = str.find(his2, pos)) != std::string::npos) {
        str.replace(pos, his2.length(), neu11);
        pos += neu11.length();
    }
    pos = 3;
    while ((pos = str.find(his3, pos)) != std::string::npos) {
        str.replace(pos, his3.length(), neu12);
        pos += neu12.length();
    }
    pos = 3;
    while ((pos = str.find(his4, pos)) != std::string::npos) {
        str.replace(pos, his4.length(), neu13);
        pos += neu13.length();

    }
    pos = 3;
    while ((pos = str.find(his5, pos)) != std::string::npos) {
        str.replace(pos, his5.length(), neu14);
        pos += neu14.length();
    }
    pos = 3;
    while ((pos = str.find(his6, pos)) != std::string::npos) {
        str.replace(pos, his6.length(), neu15);
        pos += neu15.length();
    }
    pos = 3;
    while ((pos = str.find(his7, pos)) != std::string::npos) {
        str.replace(pos, his7.length(), neu16);
        pos += neu16.length();

    }
    pos = 3;
    while ((pos = str.find(his8, pos)) != std::string::npos) {
        str.replace(pos, his8.length(), neu17);
        pos += neu17.length();
    }
    pos = 3;
    while ((pos = str.find(his9, pos)) != std::string::npos) {
        str.replace(pos, his9.length(), neu18);
        pos += neu18.length();
    }

    // him options................................................................
    pos = 3;
    while ((pos = str.find(him1, pos)) != std::string::npos) {
        str.replace(pos, him1.length(), neu19);
        pos += neu19.length();

    }
    pos = 3;
    while ((pos = str.find(him2, pos)) != std::string::npos) {
        str.replace(pos, him2.length(), neu20);
        pos += neu20.length();
    }
    pos = 3;
    while ((pos = str.find(him3, pos)) != std::string::npos) {
        str.replace(pos, him3.length(), neu21);
        pos += neu21.length();
    }
    pos = 3;
    while ((pos = str.find(him4, pos)) != std::string::npos) {
        str.replace(pos, him4.length(), neu22);
        pos += neu22.length();

    }
    pos = 3;
    while ((pos = str.find(him5, pos)) != std::string::npos) {
        str.replace(pos, him5.length(), neu23);
        pos += neu23.length();
    }
    pos = 3;
    while ((pos = str.find(him6, pos)) != std::string::npos) {
        str.replace(pos, him6.length(), neu24);
        pos += neu24.length();
    }
    pos = 3;
    while ((pos = str.find(him7, pos)) != std::string::npos) {
        str.replace(pos, him7.length(), neu25);
        pos += neu25.length();

    }
    pos = 3;
    while ((pos = str.find(him8, pos)) != std::string::npos) {
        str.replace(pos, him8.length(), neu26);
        pos += neu26.length();
    }
    pos = 3;
    while ((pos = str.find(him9, pos)) != std::string::npos) {
        str.replace(pos, him9.length(), neu27);
        pos += neu27.length();
    }

}

int main() {
    string str;
    cout << "Enter your statement : " << endl;
    getline(cin,str);
    str.append(" ");
    cout << "-----------------------------------------------" << endl;

    first_word(str);
    mid_word(str);
    symbols_word(str);

    cout << "statement after modify : " << endl << str << endl;
    cout << "-----------------------------------------------" << endl;
}