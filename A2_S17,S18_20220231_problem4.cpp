/*

 File: A2_S17,S18_20220231_problem4.cpp
 Purpose: finding the prime factors of a num
 Author: Omar Mohammed Ahmed
 Section: S17, S18
 ID: 20220231
 TA: Dr.Rana Abdelkader
 Date: 1-November-2023

*/
//---------------------

#include <iostream>
#include <vector>

void sieveOfEratosthenes(int n) {
    std::vector<bool> isPrime(n + 1, true);  // vector of size n+1 with initial value as true

    for (int p = 2; p * p <= n; ++p) { // looping till the biggest number with a square before n
        if (isPrime[p]) { // if p is a prime number
            for (int i = p * p; i <= n; i += p) {  // checking for the multiples of the numbers
                isPrime[i] = false;   // { t ,t ,t , t ,f ,t....} changing vector status for every multiple found
            }
        }
    }

    std::cout << "Prime numbers between 2 and " << n << " are:\n"; // printing the nums
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            std::cout << i << " ";
        }
    }
}

int main() {
    int n;
    std::cout << "Enter a number (n): ";
    std::cin >> n;

    sieveOfEratosthenes(n);

    return 0;
}