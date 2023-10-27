// File: A2_S1_20220012_1.cpp
// Purpose: Solve problem 1
// Author: Ahmed Ehab Shehata Ali
// Section: S1
// ID: 20220012
// TA: Maya Ahmed Kamal
// Date:  Oct 2023

#include <iostream>

using namespace std;

int main()
{
    int i;
    string sentence, corrected_sentence;

    cout << "Enter your sentence\n: ";
    //get the sentence
    getline(cin, sentence);
    cout << '\n';
    // make the first character uppercase
    corrected_sentence += toupper(sentence[0]);
    for (i = 1; i < sentence.size(); i++)
    {
        // add the first space only by check if the prev character is not a space
        if (sentence[i] == ' ' && !sentence[i - 1] == ' ')
            corrected_sentence += ' ';

        // check if any character expict the first one is uppercase 
        if (sentence[i] == toupper(sentence[i]))
            // make the character lowercase
            corrected_sentence += tolower(sentence[i]);
        else
            corrected_sentence += sentence[i];
        
        // Check for the end of the sentence
        if (sentence[i] == '.')
            break;
    }
    cout << "the corrected sentence\n: ";
    cout << corrected_sentence << '\n';
}