// File: A2_S1_20220034_11.cpp
// Purpose: Solve problem 11
// Author: Ahmed Mohamed Amer Ahmed
// Section: S1
// ID: 20220034
// TA: Maya Ahmed Kamal
// Date: 28 Oct 2023

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std ;
int main(){
    // files name
    string name1 , name2;
    // string to save files data to use it in compare
    string line1 , line2 ;
    // ifstream objects
    ifstream file1 , file2;
    cout<<"Welcome to File Comparison program.";
    // take first file name from the user and open it
    cout<<"\nPlease enter first file name :";
    cin>>name1;
    file1.open(name1);
    // check if the first file will open successfully
    if ( file1.fail() ){
        cout << "Error can't open the file ,please check the name and extension and try again\n";
        return 0;
    }
    // take second file name from the user and open it
    cout<<"\nPlease enter second file name :";
    cin>>name2;
    file2.open(name2);
    // check if the second file will open successfully
     if ( file2.fail() ){
        cout << "Error can't open the file ,please check the name and extension and try again\n";
        return 0;
    }
    // the message to make the user select comparison way
    cout<<"\nPlease select the way you want to comparison.";
    cout<<"\n1- character by character comparison.";
    cout<<"\n2- word by word comparison.\n";
    // take the number of the way to comparison
    int comparison;
    cin>>comparison;

    // character by character comparison
    if(comparison == 1){
        // counter for lines of file
        int lines=0;
        bool flag=true;
        // loop on the full file
        while( file1.good() ){
            lines++;
            // get a line from the file
            getline(file1 , line1);
            getline(file2 , line2);
            // compare lines by each other
            for(int i=0 ; i<line1.size() ; i++){
                if(line1[i]==line2[i])
                    continue;
                else{
                    flag =false;
                    cout<<"The files are not identical\n";
                    cout<<"The number of the first line that is different is : "<<lines<<'\n';
                    cout<<"The content of the first line that is different in the first file is :"<<'\n';
                    cout<<line1<<'\n';
                    cout<<"The content of the first line that is different in the second file is :"<<'\n';
                    cout<<line2<<'\n';
                    // break for loop
                    break;
                }
            }
            // break while loop
            if(!flag)
                break;
        }
        if(flag)
            cout<<"The files are identical";
    }
    else if(comparison == 2){
        // counter for lines of the file
        int lines=0;
        bool flag=true;
        // loop on the full file
        while( file1.good() ){
            lines++;
            // get line from the file
            getline(file1 , line1);
            //create an object ArrOfWords1 to take line1 as substrings
            istringstream ArrOfWords1(line1);
            string word1;
            vector<string> s1;
            // take every word and save it in an index of string vector
            while (ArrOfWords1 >> word1)
                s1.push_back(word1);
            getline(file2 , line2);
            istringstream ArrOfWords2(line2);
            string word2;
            vector<string> s2;
            while (ArrOfWords2 >> word2)
                s2.push_back(word2);
            // compare every word in s1 by every word in s2
            for(int i=0 ; i<s1.size() ; i++){
                if(s1[i]==s2[i])
                    continue;
                else{
                    flag =false;
                    cout<<"The files are not identical\n";
                    cout<<"The number of the first line that is different is : "<<lines<<'\n';
                    cout<<"The  first different word of the first file is :"<<'\n';
                    cout<<s1[i]<<'\n';
                    cout<<"The  first different word of the second file is :"<<'\n';
                    cout<<s2[i]<<'\n';
                    //break for loop
                    break;
                }
            }
            //break while loop
            if(!flag)
                break;
        }
        if(flag)
            cout<<"The files are identical";
    }
    return 0;
}
