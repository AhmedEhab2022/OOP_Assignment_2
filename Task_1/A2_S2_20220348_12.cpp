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
  string content;
  const int points;
  long occurrences;
};

Phishing_Word words[30] = {
    {"Amazon", 3, 0},
    {"Apple", 3, 0},
    {"Bank of america", 3, 0},
    {"Chase", 1, 0},
    {"Citibank", 2, 0},
    {"eBay", 3, 0},
    {"Facebook", 3, 0},
    {"Federal Bureau of Investication", 3, 0},
    {"Google", 3, 0},
    {"Internal Revenue Service", 2, 0},
    {"LinkedIn", 2, 0},
    {"Microsoft", 3, 0},
    {"Netflix", 3, 0},
    {"PayPal", 3, 0},
    {"Social Sevurity Administration", 3, 0},
    {"Twitter", 3, 0},
    {"Wells Fargo", 1, 0},
    {"American Express", 2, 0},
    {"Acpital One", 2, 0},
    {"Discover", 1, 0},
    {"Mastercard", 3, 0},
    {"Visa", 3, 0},
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
  // we create fstream object called file
  ifstream file;
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
  string msg_content;
  msg_content = buffer.str();

  long total_points = 0;

  cout << "\nThe occurrence of each word and phrase is:\n";
  for (auto word : words)
  {
    // check if the massage is bigger than the word.
    if (msg_content.size() >= word.content.size())
    {
      // loop through the massage and check for each word.
      for (int i = 0; i < msg_content.size(); i++)
      {
        // if it exist we increase the occurrence and add the 
        // word points to the total.
        if (word.content == msg_content.substr(i, word.content.size()))
        {
          word.occurrences += 1;
          total_points += word.points;
        }
      }
    }
    // output the occurrence of each word or phrase.
    cout << word.content << ": " << word.occurrences << '\n';
  }
  cout << "\nThe total points for this massage is: " << total_points;

  file.close();
}