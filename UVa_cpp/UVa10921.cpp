#include <iostream>
#include <map>

using namespace std;

string letter[8] { "ABC", "DEF", "GHI","JKL","MNO","PQRS","TUV","WXYZ"};

int main(){
    map<char, int> mp;
    for(int i=0; i<8; ++i) {
        for(auto &k : letter[i]) mp[k] = i + 2;
    }
    string s;
    while( cin >> s){
        for(int i=0; i<s.size(); ++i){
            if (s[i] == '0' || s[i] == '1' || s[i] == '-') cout << s[i];
            else cout << mp[s[i]];
        }
        cout << '\n';
    }
}