/*
File:A3_Sheet2Pb4_20220231
Purpose: creating a set
Author: Omar Mohamed Ahmed
ID:20220231
Section:s17
Date:10/12/2023
 */
//-------------------- Header
#include "bits/stdc++.h"
#include <iostream>
using namespace std;

template <class T>
//----------- template class
class SET
{
private:
    vector<T> mini_set;  // typename vector

public:
    void push(const T& item)
    {
        // pushing element if unique
        auto it = find(mini_set.begin(), mini_set.end(), item);
        if (it == mini_set.end())
            mini_set.push_back(item);
        else
            cout << "The element is already in the set." << endl;
    }

    void RemoveElement(const T& item)
    {
        // removing if the element exist
        auto it = find(mini_set.begin(), mini_set.end(), item);
        if (it != mini_set.end())
            mini_set.erase(it);
        else
            cout << "The element is not in the set." << endl;
    }

    void NumberOfItems()
    {
        cout << "The number of items in the set is: " << mini_set.size() << endl;
    }

    void findItem(const T& item)
    {
        // checking if item exists
        auto it = find(mini_set.begin(), mini_set.end(), item);
        if (it != mini_set.end())
            cout << item << " is in the set." << endl;
        else
            cout << item << " is not in the set." << endl;
    }

    T* toArray()
    {
        // turning set to an array
        T* arrayPtr = new T[mini_set.size()];
        for (int i = 0; i < mini_set.size(); i++)
            arrayPtr[i] = mini_set[i];
        cout << "The elements of the array are: ";
        for (int i = 0; i < mini_set.size(); ++i)
            cout << arrayPtr[i] << " ";
        cout << endl;
        return arrayPtr;
    }

    //-----------   overloading

    bool operator==(const SET& other)
    {
        return (mini_set == other.mini_set);
    }

    bool operator!=(const SET& other)
    {
        return (mini_set != other.mini_set);
    }
};

//------------- int main

int main()
{
    SET<int> set1, set2;
    set1.push(4);
    set1.push(2);
    set1.push(2);
    set1.RemoveElement(4);
    set1.NumberOfItems();
    set1.findItem(5);
    set1.push(10);
    int* intArray = set1.toArray();
    delete[] intArray;

    set2.push(7);
    set2.push(8);

    // sets comparison
    if (set1 == set2)
    {
        cout << "Both sets are equal.\n";
    }
    if (set1 != set2)
    {
        cout << "Both sets are not equal.\n";
    }
}
