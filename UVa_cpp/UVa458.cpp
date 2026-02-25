#include <iostream>

using namespace std;

int main(){
    string s;
    // char a = '1', b = '*', c = 'J', d = 'C';
    // cout << a - b << " | " << c - d << endl;
    while(cin >> s){
        for( char i : s ) {
            if(i == ' ') continue;
            cout << (char)(i - 7);
        }
        cout << endl;
    }

}