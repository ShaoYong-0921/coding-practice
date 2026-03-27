#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    bool first = true;
    while( n -- ){
        if (!first) cout << '\n';
        first = false;
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        cout << s2 << '\n' << s1 << '\n';

        map<char, char> mp;
        for(int i=0; i<s1.size(); ++i) mp[s1[i]] = s2[i];
        while(getline(cin, s) && s != ""){
            for(int i=0; i<s.size(); ++i){
                if (mp[s[i]]) cout << mp[s[i]];
                else cout << s[i];
            }
            cout << '\n';
        }
    }
}