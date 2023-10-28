// File: A2_S1_20220034_2.cpp
// Purpose: Solve problem 2
// Author: Ahmed Mohamed Amer Ahmed
// Section: S1
// ID: 20220034
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
#include <string>

using namespace std ;
int main(){
    string s;
    // a message to make the user enter the sentence
    cout<<"Please enter your sentence :"<<'\n';
    getline(cin , s);
    // loop over the sentence
    for(int i =0 ; i<s.size() ; i++){
        // at the beginning of the sentence
        if(i == 0){
            // Replace "he" with "he or she"
            if( (s[i] == 'h' || s[i] == 'H' ) && (s[i+1] == 'e' ) && (s[i+2] ==' ' || s[i+2] =='.' || s[i+2] =='?') ) {
                if(s[i] == 'H')
                    cout<<"He or she"<<s[i+2];
                else
                    cout<<"he or she"<<s[i+2];
                i += 2;
            }
            // Replace "him" with "him or her"
            else if ( (s[i] == 'h' || s[i] == 'H') && (s[i+1] == 'i') && (s[i+2] == 'm') && ((s[i+3] ==' ' || s[i+3] =='.' || s[i+3] =='?')) ){
                 if(s[i] == 'H')
                    cout<<"Him or her"<<s[i+3];
                else
                    cout<<"him or her"<<s[i+3];
                i += 3;
            }
            // Replace "his" with "his or hers"
            else if ( (s[i] == 'h' || s[i] == 'H') && (s[i+1] == 'i') && (s[i+2] == 's') && ((s[i+3] ==' ' || s[i+3] =='.' || s[i+3] =='?')) ){
                 if(s[i] == 'H')
                    cout<<"His or hers"<<s[i+3];
                else
                    cout<<"his or hers"<<s[i+3];
                i += 3;
            }
            // Replace "himself" with "himself or herself"
            else if ( (s[i] == 'h' || s[i] == 'H') && (s[i+1] == 'i') && (s[i+2] == 'm') && (s[i+3] == 's') && (s[i+4] == 'e') && (s[i+5] == 'l') && (s[i+6] == 'f') && ((s[i+7] ==' ' || s[i+7] =='.' || s[i+7] =='?')) ){
                 if(s[i] == 'H')
                    cout<<"Himself or herself"<<s[i+7];
                else
                    cout<<"himself or herself"<<s[i+7];
                i += 7;
            }

            else
                cout<<s[i];
        }
        // if i != 0
        else if(s[i-1] ==' ' || s[i-1] =='.' || s[i-1] =='?'){
            // Replace "he" with "he or she"
            if( (s[i] == 'h' || s[i] == 'H' ) && (s[i+1] == 'e' ) && (s[i+2] ==' ' || s[i+2] =='.' || s[i+2] =='?') ) {
                if(s[i] == 'H')
                    cout<<"He or she"<<s[i+2];
                else
                    cout<<"he or she"<<s[i+2];
                i += 2;
            }
            // Replace "him" with "him or her"
            else if( (s[i] == 'h' || s[i] == 'H') && (s[i+1] == 'i') && (s[i+2] == 'm') && ((s[i+3] ==' ' || s[i+3] =='.' || s[i+3] =='?')) ){
                if(s[i] == 'H')
                    cout<<"Him or her"<<s[i+3];
                else
                    cout<<"him or her"<<s[i+3];
                i += 3;
            }
            // Replace "his" with "his or hers"
            else if ( (s[i] == 'h' || s[i] == 'H') && (s[i+1] == 'i') && (s[i+2] == 's') && ((s[i+3] ==' ' || s[i+3] =='.' || s[i+3] =='?')) ){
                 if(s[i] == 'H')
                    cout<<"His or hers"<<s[i+3];
                else
                    cout<<"his or hers"<<s[i+3];
                i += 3;
            }
            // Replace "himself" with "himself or herself"
            else if ( (s[i] == 'h' || s[i] == 'H') && (s[i+1] == 'i') && (s[i+2] == 'm') && (s[i+3] == 's') && (s[i+4] == 'e') && (s[i+5] == 'l') && (s[i+6] == 'f') && ((s[i+7] ==' ' || s[i+7] =='.' || s[i+7] =='?')) ){
                 if(s[i] == 'H')
                    cout<<"Himself or herself"<<s[i+7];
                else
                    cout<<"himself or herself"<<s[i+7];
                i += 7;
            }

            else
                cout<<s[i];
        }

        else
            cout<<s[i];
    }
    return 0;
}
