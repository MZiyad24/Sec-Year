//---------------------- Description
/*
File : A3_SheetPb2_20221067.cpp
Purpose : checking files similarity
Author : Ziyad Mohammed Abdullah
ID : 20221067
Section : S17,S18
Date : 4/12/2023

*/
//---------------------- Headers

#include "iostream"
#include "bits//stdc++.h"
#include "string"
#include "fstream"
#include "vector"
using namespace std;

//----------------------- classes

//ifstream file;
//string main_file;
class StringSet
{
protected:
    vector<string>set1,set2;  // for saved words  // the other one for the fixed string
    string word,main_file;
public:
    StringSet()  // empty constructor
    {
//        validity("check");
    };
    StringSet(string filename,int i)  // file parametrized constructor
    {
        Load_file(filename);   // to read the given file
    }
    StringSet(string str)   // string parameterized constructor
    {
        checker(str);           // checking for alphabets and punctuation
        splitter(str);         //  tokenizing string
        validity(str);         //  making sure about validation

    }
    void push(string a)       //  pushing a string
    {
        checker(a);
        set1.push_back(a);
    }
    void remove(string const a)     // removing a string
    {
        std::remove(set1.begin(), set1.end(),a);
    }
    void clear()      // clearing the set
    {
        set1.clear();
    }
    int count()    // getting the size of a set
    {
        return set1.size();
    }
    void print()      // displaying content of a set
    {
        for (auto it : set1)
        {
            cout<<it<<"\n";
        }
    }
    void Load_file(string filename)     // loading file checking its validation
    {
        filename+=".txt";
        ifstream file(filename);
        if ( file.is_open()) {
            while (file >> word)
            {
                checker(word);
                validity(word);
            }
        }
        else
        {
            cout<<"error while opening the file!\n";
            exit(0);
        }
    }
    void checker(string& inp)
    {
        inp.erase(remove_if(inp.begin(), inp.end(), ::ispunct), inp.end());  // removes punctuation from a string
        transform(inp.begin(), inp.end(), inp.begin(), ::tolower);  // transforms to lower  (to lower-> execution)

    }
    void validity(string const s)
    {
        if (set2.size()>0)
        {
            for (auto it : set2)
            {
                if (std::find(set1.begin(), set1.end(), it) == set1.end())
                {
                    set1.push_back(it);
                }
            }
        }
        else
        {
            if (std::find(set1.begin(), set1.end(), s) == set1.end())
            {
                set1.push_back(s);
            }
        }
    }
    StringSet operator * (StringSet s)    // calculating the Intersection of two sets
    {
        StringSet interset;
        for (auto it : this->set1)
        {
            if (std::find(s.set1.begin(), s.set1.end(),it)!=s.set1.end())
            {
                interset.set1.push_back(it);
            }
        }
        return interset;
    }
    StringSet operator + (StringSet s)     // calculating the unisokaron of two sets
    {
        StringSet unionset;
        for (auto it : this->set1)
        {
            unionset.set2.push_back(it);
        }
        for (auto it : s.set1)
        {
            unionset.set2.push_back(it);
        }
        unique(unionset.set2.begin(),unionset.set2.end());
        return unionset;
    }
    friend double Similarity (StringSet first , StringSet second);  // calculating the similarity of the given docs
    void splitter(string str)
    {
        string wrd;int checkpoint=0;
        for (int i = 0; i <= str.size(); ++i)
        {
            if (str[i]==' '||i==str.size())
            {
                for (int j = checkpoint; j < i; ++j)
                {
                    wrd+=str[j];
                }
                checkpoint=i+1;  // the beginning of the next string
                set2.push_back(wrd);
                wrd.clear();
                if (i==str.size())
                {
                    break;
                }
            }
        }
    }

};

//-------------------- Functions

double Similarity (StringSet first , StringSet second)
{
    StringSet distinct = first * second;
    return (distinct.set1.size())/(sqrt(first.set1.size())* sqrt(second.set1.size()));
}

//-------------------- main

int main()
{
    string filename,input;
    int check;
    cout<<"If you want to check fil with file choose 1 \n for file and string choose 2 \n for two strings choose 3 : ";
    cin>>check;
    if (check==1) {
        cout << "pls enter the first file you want to check: ";
        cin>>input;
        StringSet file1(input,0);
        cout << "pls enter the second file you want to check: ";
        cin >> filename;
        StringSet file2(filename, 0);

        StringSet ans=file1*file2;
        cout<<Similarity(file1,file2)<<"\n";
        file1.print();
        cout<<"\n";
        file2.print();
        cout<<"\n";
        file1.push("element1");
        file2.push("element2");
        file1.print();
        cout<<"\n";
        file2.remove("chocolate");
        file2.print();
        cout<<"\n";
        cout<<"similarity level: "<<Similarity(file1,file2)<<"\n";
        StringSet uni=file1+file2;
        uni.validity("check");
        uni.print();
    }
    else if (check==2)
    {
        cin.ignore();   // to empty the cin buffer
        cout << "pls enter the string you want to check: ";
        getline(cin,input);
        StringSet file1(input);
        cout << "pls enter the file you want to check: ";
        cin >> filename;
        StringSet file2(filename, 0);

        StringSet ans=file1*file2;
        cout<<"similarity level: "<<Similarity(file1,file2)<<"\n";
        file1.print();
        cout<<"\n";
        file2.print();
        cout<<"\n";
        file1.push("element1");
        file2.push("element2");
        file1.print();
        cout<<"\n";
        file2.remove("chocolate");
        file2.print();
        cout<<"\n";
        cout<<Similarity(file1,file2)<<"\n";
        StringSet uni=file1+file2;
        uni.validity("check");
        uni.print();
    }
    else
    {
        cin.ignore();  // to empty the cin buffer
        cout << "pls enter the first string you want to check: ";
        getline(cin,input);
        StringSet file1(input);
        cout << "pls enter the second string you want to check: ";
        getline(cin,filename);
        StringSet file2(filename);

        StringSet ans=file1*file2;
        cout<<"similarity level: "<<Similarity(file1,file2)<<"\n";
        file1.print();
        cout<<"\n";
        file2.print();
        cout<<"\n";
        file1.push("element1");
        file2.push("element2");
        file1.print();
        cout<<"\n";
        file2.remove("chocolate");
        file2.print();
        cout<<"\n";
        cout<<Similarity(file1,file2)<<"\n";
        StringSet uni=file1+file2;
        uni.validity("check");
        uni.print();
    }

}
