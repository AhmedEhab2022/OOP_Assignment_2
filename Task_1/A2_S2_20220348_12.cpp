// File: A2_S2_20220348_12.cpp
// Purpose: solution of the 12'rd problem in the first task in assignment 2 OOP
// Author: Mohanad Abdullrahem Abdullrahman Ahmed
// Section: S2
// ID: 20220348
// TA: Maya Ahmed Kamal
// Date: 26 Oct 2023

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Phishing_Word
{
  string word;
  int points;
  long occurrences;
};

Phishing_Word words[30] = {
    {"amazon", 3, 0},
    {"apple", 3, 0},
    {"bank of america", 3, 0},
    {"chase", 1, 0},
    {"citibank", 2, 0},
    {"eBay", 3, 0},
    {"facebook", 3, 0},
    {"federal bureau of investication", 3, 0},
    {"google", 3, 0},
    {"internal revenue service", 2, 0},
    {"linkedIn", 2, 0},
    {"microsoft", 3, 0},
    {"netflix", 3, 0},
    {"payPal", 3, 0},
    {"social sevurity administration", 3, 0},
    {"twitter", 3, 0},
    {"wells fargo", 1, 0},
    {"american express", 2, 0},
    {"acpital one", 2, 0},
    {"discover", 1, 0},
    {"mastercard", 3, 0},
    {"visa", 3, 0},
    {"account suspended", 3, 0},
    {"alert!", 2, 0},
    {"change your password", 3, 0},
    {"Confirm your account", 3, 0},
    {"Fraudulent activity detected", 2, 0},
    {"Important security update required", 3, 0},
    {"Login attempt failed", 3, 0},
    {"Your account has been hacked", 3, 0},
};

int main()
{
  string file_name;
  // cout << "Please enter the file name: ";
  // cin >> file_name;

  // we create fstream object called file
  ifstream file;
  // file.open(file_name + ".txt");
  // file.open("C:\\Users\\mhnda\\Desktop\\Code\\FCAI-OOP\\Assignment-2\\OOP_Assignment_2\\Task_1\\Q12_Phishing_message.txt");
  file.open("Q12_Phishing_message.txt");

  // check if the file is opened successfully.
  // if not we output an error message.
  if (file.fail())
  {
    cout << "cannot open the file. please try again.\n";
    cout << "make sure that the file is in the same dir with the program file.\n";
    return 1;
  }

  // we create a string stream object called buffer.
  stringstream buffer;

  // rdbuf method returns a pointer to the stream buffer object
  // associated with the file fstream object.
  // the stream insertion operator (<<) will read the content
  // into the string stream buffer object.
  buffer << file.rdbuf();

  // we read the content from the string stream buffer
  // into the string content.
  string content;
  content = buffer.str();

  cout << content;

  file.close();
}

// Amazon
// Apple
// Bank of America
// Chase
// Citibank
// eBay
// Facebook
// Federal Bureau of Investigation (FBI)
// Google
// Internal Revenue Service (IRS)
// LinkedIn
// Microsoft
// Netflix
// PayPal
// Social Security Administration (SSA)
// Twitter
// Wells Fargo
// American Express
// Capital One
// Discover
// Mastercard
// Visa

// Account suspended
// Alert!
// Change your password immediately
// Confirm your account information
// Fraudulent activity detected
// Important security update required
// Login attempt failed
// Your account has been hacked