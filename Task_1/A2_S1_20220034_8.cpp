// File: A2_S1_20220034_8.cpp
// Purpose: Solve problem 8
// Author: Ahmed Mohamed Amer Ahmed
// Section: S1
// ID: 20220034
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
#include <string>
using namespace std;

// the recursion function
void pattern(int n, int m) {
    if (n == 0) {
    }
    else {
        pattern(n/2 , m ) ;
        // cout blanks
        for (int i = 0; i < m ; i++) {
            cout << " ";
        }
        // cout asterisks
        for (int i = 0; i < n; i++) {
            cout << "* ";
        }
        cout << '\n';
        pattern(n/2, m+n  );
    }
}

int main() {
    cout<<"Please enter number of asterisks to represent The longest line of the pattern : ";
    int n , i ;
    cin>> n ;
    cout<<"Please enter number of a column to start after : ";
    cin>> i ;
    pattern(n , i);
    return 0;
}
