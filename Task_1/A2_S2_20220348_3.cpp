// File: A2_S2_20220348_3.cpp
// Purpose: solution of the 3'rd problem in the first task in assignment 2 OOP
// Author: Mohanad Abdullrahem Abdullrahman Ahmed
// Section: S2
// ID: 20220348
// TA: Maya Ahmed Kamal
// Date: 26 Oct 2023

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string target, string delimiter);

int main()
{
  vector<string> v;
  v = split("do re mi fa so la ti do", " ");
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}

vector<string> split(string target, string delimiter)
{
  if (delimiter == "")
    delimiter = " ";
    
  vector<string> answer;
  string current_word = "", word_to_compare = "";

  for (int i = 0; i < target.size(); i++)
  {
    // we iterate over the string from i to i + delimiter size to
    // create the word to compare with the delimiter.
    for (int j = i; j < i + delimiter.size(); j++)
    {
      word_to_compare += target[j];
    }

    // if the word_to_compare is the delimiter then we push
    // the current word in the vector.
    if (word_to_compare == delimiter)
    {
      answer.push_back(current_word);
      current_word = "";
      i += delimiter.size() - 1;
    }
    // else if it's the last char and it's not the delimiter
    // then we add it to the current word and then push it.
    else if (i == target.size() - 1)
    {
      current_word += target[i];
      answer.push_back(current_word);
    }
    // else we just add the char to the current word.
    else
    {
      current_word += target[i];
    }

    // in evry iteration we empty the word to compare with the delimiter.
    word_to_compare = "";
  }

  return answer;
}