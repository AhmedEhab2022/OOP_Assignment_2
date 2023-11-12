// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name: .......cpp
// Last Modification Date:	1/11/2023

// Author1 : Ahmed Ehab Shehata Ali
// ID : 20220012
// Section: S1
// email : am8122004@gmail.com

// Author2 : Ahmed Mohamed Amer Ahmed
// ID : 20220034
// Section: S1
// email : ahmedamer42214953@gmail.com

// Author3 : Mohanad Abdullrahem Abdullrahman
// ID : 20220348
// Section: S2
// email : mhndahmd031@gmail.com

// TA: Khaled Ibrahem

// Purpose: ........

#include "machine.cpp"
#include "screen.cpp"
#include "memory.cpp"
#include "regeisters.cpp"
#include <iostream>
using namespace std;

int main()
{
  Machine m;
  cout << "\n======================\n";
  m.displayStatus();
  m.displayMenu();
  m.excuteProgram();
}
