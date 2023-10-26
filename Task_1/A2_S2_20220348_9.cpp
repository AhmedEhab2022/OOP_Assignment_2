// File: A2_S2_20220348_9.cpp
// Purpose: solution of the 9'rd problem in the first task in assignment 2 OOP
// Author: Mohanad Abdullrahem Abdullrahman Ahmed
// Section: S2
// ID: 20220348
// TA: Maya Ahmed Kamal
// Date: 26 Oct 2023

#include <iostream>
using namespace std;

class teddyBear
{
private:
  /* data */
public:
  teddyBear() {}
  ~teddyBear() {}
  static bool bears(int n)
  {
    // the base case.
    if (n < 42)
    {
      return false;
    }
    else if (n == 42)
    {
      return true;
    }

    // array of all the possible cases.
    bool cases[3];
    if (n % 2 == 0)
    {
      cases[0] = bears(n / 2);
    }
    if ((n % 3 == 0 || n % 4 == 0) && ((n % 10) * ((n % 100) / 10)))
    {
      cases[1] = bears(n - ((n % 10) * ((n % 100) / 10)));
    }
    if (n % 5 == 0)
    {
      cases[2] = bears(n - 42);
    }

    // if any of the cases is true we return true.
    if (cases[0] || cases[1] || cases[2])
    {
      return true;
    }
    // else we return false.
    return false;
  }
};

int main()
{
  teddyBear b;
  cout << b.bears(250);
}
