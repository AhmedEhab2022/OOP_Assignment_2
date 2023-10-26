// File: A2_S2_20220348_6.cpp
// Purpose: solution of the 6'rd problem in the first task in assignment 2 OOP
// Author: Mohanad Abdullrahem Abdullrahman Ahmed
// Section: S2
// ID: 20220348
// TA: Maya Ahmed Kamal
// Date: 26 Oct 2023

#include <iostream>
using namespace std;

class binary
{
private:
  /* data */
public:
  binary() {}
  ~binary() {}
  static void binaryPrint(int n)
  {
    // a condition to prevent any leading zeros.
    if (n == 1)
    {
      cout << '1';
      return;
    }
    // the base case.
    if (n == 0)
    {
      cout << '0';
      return;
    }

    // we call the function before printing
    // so it prints from the last to the first.
    binaryPrint(n / 2);

    if (n % 2 == 0)
    {
      cout << '0';
    }
    else
    {
      cout << '1';
    }
  }
  static void numbers(string prefix, int k)
  {
    // the base case.
    if (k == 0)
    {
      cout << prefix << '\n';
      return;
    }
    numbers(prefix + "0", k - 1);
    numbers(prefix + "1", k - 1);
  }
};

int main()
{
  binary num;
  num.binaryPrint(27);
  cout << "\n==================\n";
  num.numbers("00101", 2);
}