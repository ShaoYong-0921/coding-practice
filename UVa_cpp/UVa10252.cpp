#include <iostream>

using namespace std;

int alph1[30], alph2[30];

int main(){
    string s1, s2;
    while( getline(cin, s1) && getline(cin, s2) ){
        for(int i=0; i<30; i++){
            alph1[i] = 0;
            alph2[i] = 0;
        }
        for(int i=0; i<s1.size(); i++)
            alph1[s1[i] - 'a'] ++;
        for(int i=0; i<s2.size(); i++)
            alph2[s2[i] - 'a'] ++;
        for(int i=0; i<26; i++){
            if( alph1[i] == 0 || alph2[i] == 0) continue;
            else{
                // cout << (char)(i + 'a');
                if(alph1[i] > alph2[i]) swap(alph1[i], alph2[i]);
                for(int j=0; j<alph1[i]; j++){
                    cout << (char)( i + 'a');
                }
            }
        }
        cout << '\n';
    }

}