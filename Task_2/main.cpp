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

// TA: Maya Ahmed Kamal

// Purpose: ........

#include "BigReal.cpp"
#include <iostream>
#include <string>

int main()
{
    BigReal n1("11.9000000000000000000000000000000001");
    BigReal n2("-2333333333339.1134322222222292");
    BigReal n3("2333333333339.");
    BigReal n4(".1134322222222292");
    BigReal n5("."); // invalid
    BigReal n6("-11.9000000000000000000000000000000001");
    BigReal n7("-1.234");
    BigReal n8("-A12.999000000"); // invalid
    BigReal n9("-2.234");
    cout << "\n=====================\n";
    cout << n1.getNum() << '\n';
    cout << "size: " << n1.getSize() << '\n';
    cout << n2.getNum() << '\n';
    cout << "size: " << n2.getSize() << '\n';
    cout << n3.getNum() << '\n';
    cout << "size: " << n3.getSize() << '\n';
    cout << n4.getNum() << '\n';
    cout << "size: " << n4.getSize() << '\n';
    cout << n8.getNum() << '\n';
    cout << "size: " << n8.getSize() << '\n';
    cout << "\n=====================\n";
    cout << boolalpha;
    cout << (n1 < n2) << '\n'; // false
    cout << (n2 < n1) << '\n'; // true
    cout << (n1 < n3) << '\n'; // true
    cout << (n3 < n4) << '\n'; // false
    cout << (n2 < n3) << '\n'; // true
    cout << (n1 < n4) << '\n'; // false
    cout << "\n=====================\n";
    cout << (n1 > n2) << '\n'; // true
    cout << (n2 > n1) << '\n'; // false
    cout << (n1 > n3) << '\n'; // false
    cout << (n3 > n4) << '\n'; // true
    cout << (n2 > n3) << '\n'; // false
    cout << (n1 > n4) << '\n'; // true
    cout << "\n=====================\n";
    cout << (n1 == n2) << '\n'; // false
    cout << (n2 == n1) << '\n'; // false
    cout << (n1 == n3) << '\n'; // false
    cout << (n3 == n3) << '\n'; // true
    cout << (n2 == n2) << '\n'; // true
    cout << (n1 == n1) << '\n'; // true
    cout << (n1 == n6) << '\n'; // false
    cout << "\n=====================\n";
    cout << n1 << '\n' << n2 << '\n' << n3 << '\n';
    cout << "\n=====================\n";
    cout << n7 << '\n';
    cout << "\n=====================\n";
    n9 = n1 + n3;
    cout << n9 << '\n';
    cout << "\n=====================\n";
    // n3 = n3 + BigReal (0.9);
    cout << "\n=====================\n";
    n8 = n1;
    n8.setSign('-');
    cout << n8 << '\n';
    cout << n1 << '\n';
}