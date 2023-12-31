//-------------- Description
/*
File : A3_Sheet2Pb5_20221067
Purpose: CPP task manager
Author : Ziyad Mohammed Abdullah
ID:20221067
Section: S17,S18
Date:7/12/2023
 */

//------------- Headers

#include"iostream"
#include "fstream"
#include "bits/stdc++.h"


using namespace std;

//------------ classes
class proccess
{
protected:
    vector<string>name,PID,mem;
public:
    void List()
    {
        string line,temp;
        int count=0;
        ifstream file("Tasks.txt");
        while(getline(file,line))
        {
            if (count<1)
            {
//                for (int i = 0; i < 77; ++i)
//                {
//                    temp+=line[i];
//                    if (count ==0)      // first part of the figure
//                    {
//                        if (i==33)
//                        {
//                            Figure1 += temp;
//                            temp.clear();
//                        }
//                        if (i == 63)
//                        {
//                            temp.clear();
//                        }
//                        else if (i == 76)
//                        {
//                            Figure1+=temp;
//                            temp.clear();
//                        }
//                    }
//                    else if (count == 1)   // the memory part of the figure
//                    {
//                        if (i==25)
//                        {
//                            Figure2 += temp;
//                            temp.clear();
//                        }
//                        if (i>=33 && i<42)
//                        {
//                            temp[i-33]=' ';
//                        }
//                        if (i>=50 && i<60)
//                        {
//                            temp[i-33]=' ';
//                        }
//                        else if (i>=60)
//                        {
//                            temp[i-33]='=';
//                        }
//                        if (i == 65)
//                        {
//                            Figure2+=temp;
//                            temp.clear();
//                        }
//                    }
//                }
                count++;
                continue;
            }
            for (int i = 0; i < 74; ++i)
            {
                temp += line[i];
                if (i == 25)
                {
                    name.push_back(temp);
                    temp.clear();
                }
                else if (i == 33)
                {
                    PID.push_back(temp);
                    temp.clear();
                }
                if (i == 63)
                {
                    temp.clear();
                }
                else if (i == 73)
                {
                    mem.push_back(temp);
                    temp.clear();
                }
            }
        }
    }
};
class ProcessList:public proccess
{
protected:
//    vector<string>name,PID,mem;
    vector<pair<pair<string,string>,string>>ans;  // name, pid , memory together
    string Figure1,Figure2;
public:
    ProcessList()
    {
        List();
        compile();
    }

    void compile ()
    {
        for (int i = 0; i < mem.size(); ++i)
        {
            ans.push_back(make_pair(make_pair(name[i],PID[i]),mem[i]));
        }
    }
    void sort_name()
    {
        std::sort(ans.begin(), ans.end());
    }
    static bool PIDsort (const pair<pair<string,string>,string>&first, const pair<pair<string,string>,string>&sec)
    {
        return first.first.second<sec.first.second;
    }
    void sort_PID()
    {
        std::sort(ans.begin(), ans.end(),PIDsort);   // static comparator to compare the second element
    }
    void sort_mem()
    {
        std::sort(ans.begin(), ans.end(),memsort);
    }
    static bool memsort (pair<pair<string,string>,string>&first,pair<pair<string,string>,string>&sec)
    {
        return first.second<sec.second;
    }
    void display()
    {
        cout<<"Image Name"<<"\t\t\t\t"<<"PID"<<"\t\t"<<"Mem Usage\n";
        Figure1.clear();
//        cout<<"=========="<<"\t\t\t\t"<<"=========="<<"\t"<<"========\n";
        for (auto &it : ans)
        {
            if (it.second[0]=='=')
            {
                Figure1+=it.first.first;
                Figure1+="\t\t";
                Figure1+=it.first.second;
                Figure1+="\t";
                Figure1+=it.second;
                continue;
            }
            it.second+=" K";
        }
        cout<<Figure1<<"\n";
        for (auto it :ans)
        {
            if (it.second[0]=='=')
            {
                continue;
            }
            cout<<it.first.first<<"\t\t"<<it.first.second<<"\t"<<it.second<<"\n";
        }
    }

};

int main()
{
    ProcessList P;
    cout<<"choose how you want your task manager sorted \n 1.by name \n 2.by PID \n 3.by memory usage: ";
    int check;
    cin>>check;
    if (check==1)
    {
        P.sort_name();
        cout<<"\n\n";
        P.display();
    }
    else if (check==2)
    {
        cout<<"\n\n";
        P.sort_PID();
        P.display();
    }
    else
    {
        cout<<"\n\n";
        P.sort_mem();
        P.display();
    }
}



//tasklist>ClionProjects/untitled2/cmake-build-debug/Tasks.txt
