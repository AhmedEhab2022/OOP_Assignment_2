// File: A2_S1_20220012_1.cpp
// Purpose: Solve problem 1
// Author: Ahmed Ehab
// Section: S1
// ID: 20220012
// TA: ……………………
// Date:  Oct 2023

#include <iostream>

using namespace std;

int main()
{
    int i;
    string sentence, corrected_sentence;

    cout << "Enter your sentence\n: ";
    getline(cin, sentence);
    cout << '\n';
    corrected_sentence += toupper(sentence[0]);
    for (i = 1; i < sentence.size(); i++)
    {
        if (sentence[i] == ' ' && !sentence[i - 1] == ' ')
            corrected_sentence += ' ';

        if (sentence[i] == toupper(sentence[i]))
            corrected_sentence += tolower(sentence[i]);
        else
            corrected_sentence += sentence[i];
    }
    cout << "the corrected sentence\n: ";
    cout << corrected_sentence << '\n';
}