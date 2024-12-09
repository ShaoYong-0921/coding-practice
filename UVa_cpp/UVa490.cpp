#include <iostream>

using namespace std;

char senten[105][105];

int main(){
    string s;
    int row = 0, column = 0;
    while( getline(cin, s)){
        if (column < s.size()) column = s.size();
        for(int i=0; i<s.size(); i++){
            senten[row][i] = s[i];
        }
        row ++;
    }
    // cout << row << "|" << column << '\n';
    for(int i=0; i<column; i++){
        for(int j=row-1; j>=0; j--){
            if (senten[j][i]) cout << senten[j][i];
            else cout << " ";
        }
        cout << '\n';    
    }
}