#include <iostream>
#include <map>

using namespace std;

int main(){
    string str;
    int n;
    map<char, int> mp;
    cin >> n;
    getline(cin, str);
    while(n --){
        string s;
        getline(cin, s);
        for(int i=0; i<s.size(); i++){
            if ('a' <= s[i] && s[i] <= 'z')
                s[i] -= 'a' - 'A';
            if ('A' <= s[i] && s[i] <= 'Z'){
                mp[s[i]] ++;
            }
        }
        // cout << s << '\n';
    }
    int currmax = 0;
    for(map<char, int> :: iterator it=mp.begin(); it!=mp.end(); ++it)
        if (it -> second > currmax) currmax = it -> second;
    for(int i=currmax; i>0; i--){
        for(auto it = mp.begin(); it!=mp.end(); ++it)
            if (it -> second == i) cout << it->first << " " << it ->second << '\n';
    }
    
}