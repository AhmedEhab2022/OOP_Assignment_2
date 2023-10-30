// File: A2_S1_20220012_10.cpp
// Purpose: Solve problem 10
// Author: Ahmed Ehab Shehata Ali
// Section: S1
// ID: 20220012
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    int i, j;
    string line, output = "", output2 = "";
    unordered_map<string, vector<string> > look_up_table;

    // Open the look up table file.
    ifstream lookUpF("Q10_look_up_table.txt");

    while (getline(lookUpF, line))
    {
        // Process the line to store it in the map
        string key = "";
        vector<string> values;

        for (i = 0; line[i] != ':'; i++)
            key += line[i];

        i += 2;
        string value = "";

        while (i < line.size())
        {
            if (line[i] != ',')
                value += line[i];
            else
            {
                values.push_back(value);
                value = "";
                i++;
            }
            i++;
        }
        values.push_back(value);
        look_up_table[key] = values;
    }
    lookUpF.close();

    // Open the Arabic message or post file.
    ifstream message_postF("Q10_Message_or_Post3.txt");

    while (getline(message_postF, line))
    {
        // Process the line to store it in one string
        string word = "";
        for (i = 0; i < line.size() + 1; i++)
        {
            // If the current letter in the line is space or the end of the line
            // it means that the word is completed
            if (line[i] == ' ' || line[i] == '\0')
            {
                // add a new space after each word expect the last one in the line
                if (output != "" && output[output.size() - 1] != '\n')
                        output += ' ';

                // Check for the word is in the look up table or not
                // if it in look up table then the program choose one of it's values randomly to replace it
                // else it add the word
                if (look_up_table.count(word) == 0)
                    output += word;
                else
                {
                    // Process that done to generate a random index  
                    int random = rand() % look_up_table[word].size();
                    output += look_up_table[word][random];
                }
                word = "";
            }
            // Add the letter to the word as the word is not completed
            else
                word += line[i];
        }
        output += '\n';
    }
    for (i = 0; i < output.size() - 1; i++)
        output2 += output[i];

    // Close the message or post file
    message_postF.close();

    // Open a new file that contains the edited message or post
    ofstream fout("Q10_Message_or_Post3_edit.txt");
    // Add the Arabic text in the new file
    fout << output2;
    // Close the new file
    fout.close();
    return 0;
}