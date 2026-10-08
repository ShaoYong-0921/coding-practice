#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    map<string, vector<string>> mp;
    string s;
    while(cin >> s && s != "XXXXXX"){
        string sorted = s; sort(sorted.begin(), sorted.end());
        mp[sorted].push_back(s);
    }
    while(cin >> s && s != "XXXXXX"){
        string sorted = s; sort(sorted.begin(), sorted.end());
        if (!mp[sorted].empty()){
            sort(mp[sorted].begin(), mp[sorted].end());
            for(auto &i : mp[sorted]) {
                cout << i << '\n';
            }
        }
        else {
            cout << "NOT A VALID WORD\n";
        }
        cout << "******\n";
    }
}