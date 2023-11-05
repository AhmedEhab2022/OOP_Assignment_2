// File: A2_S1_20220034_5.cpp
// Purpose: Solve problem 5
// Author: Ahmed Mohamed Amer Ahmed
// Section: S1
// ID: 20220034
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
#include <map>

using namespace std ;

multimap <int , string , greater<int> > lis;
string name , last_name;
int score , last_score;
bool select();
int menu_select();
void add_player();
void print_top_scores();
void find_out();

int main(){
    bool flag=true ;
    cout<<"Welcome ^_^\n";
    // loop on the menu
    while(flag){
        flag = select();
    }
    return 0;
}

bool select(){
    // take a number from the user and do a function
    int num = menu_select();
    switch (num) {
        case 1 :
            add_player();
            return true;
            break;
        case 2 :
            print_top_scores();
            return true;
            break;
        case 3 :
            find_out();
            return true;
            break;
        case 0 :
            return false ;
            break;
    }
}

int menu_select(){
    // the menu that the user will use
    int num ;
    cout<<"Please select an option to invoke or 0 to exit : \n";
    cout<<"1- Add a new player and score.\n";
    cout<<"2- Print the top 10 names and scores.\n";
    cout<<"3- Find out the highest number of a player.\n";
    cout<<"0- exit.\n";
    cin>> num;
    return num;
}

void add_player(){
    // make the user enter a name and score
    cout<<"Please enter player's name and his or her score : \n";
    cin>>name>>score;
    // if the list is not full the score will be inserted to the map
    if(lis.size()<10){
        lis.insert({score , name});
        // save a value of last score in the map to use it to compare
        auto it = lis.rbegin();
        last_name=(*it).second;
        last_score=(*it).first;
    }
    else{
        // if the list is full , the program will compare the current score with last score in the map
        // if the current score is bigger we will delete the last score then we will add the current score
        if(score > last_score){
            lis.erase(prev(lis.end()));
            lis.insert({score , name});
            // save a value of last score in the map to use it to compare
            auto it = lis.rbegin();
            last_name=(*it).second;
            last_score=(*it).first;
        }
        // if the current score is less than the last score the program will display a message
        else if(score <= last_score){
            cout<<"Sorry ,The list is filled with higher scores\n\n";
        }
    }
}

//print top 10 scores
void print_top_scores(){
    int i = 0;
    for(auto prt = lis.begin() ; prt != lis.end(); prt++){
         i++;
        cout<< i << "-" <<(*prt).second<<"   "<< (*prt).first<<'\n';
    }
}

void find_out(){
    string player_name;
    bool name_printed = false;
    // take a player name from the user
    cin>>player_name;
    // loop over the map to try to find the player name
    for(auto it1 = lis.begin() ; it1 != lis.end(); it1++){
        // if the player is exist the program will output player name and the score
        if((*it1).second == player_name){
            cout<< (*it1).second<<"   "<< (*it1).first<<"\n\n";
            name_printed = true;
            break;
        }
    }
    // the message if the program could not find the player at top 10
    if(name_printed == false){
        cout<<"player's name has not been input or is not in the top 10.\n\n";
    }
}

