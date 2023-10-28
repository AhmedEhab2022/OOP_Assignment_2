// File: A2_S1_20220012_4.cpp
// Purpose: Solve problem 4
// Author: Ahmed Ehab Shehata Ali
// Section: S1
// ID: 20220012
// TA: Maya Ahmed Kamal
// Date: 25 Oct 2023

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, i, j, k;

    // Note: n = N - 1

    cout << "Enter the upper limit: ";
    cin >> n;
    int arr[--n];

    // store the numbers from 2 to N
    for (i = 0, j = 2; i < n; i++, j++)
        arr[i] = j;

    // filter numbers until square root of N
    for (i = 0; i + 2 < sqrt(n + 1); i++)
    {
        k = 2;
        // if the number is already removed then go to the next
        if (arr[i] == 0)
            continue;

        j = arr[i];
        while (j * k <= n + 1)
        {
            // remove number by make it zero
            arr[j * k - 2] = 0;
            k++;
        }
    }
    cout << "Prime numbers: ";
    // print the prime numbers
    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            cout << arr[i] << ' ';
    }
    cout << '\n';
}