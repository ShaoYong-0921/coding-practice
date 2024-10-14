#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string , int> mp;
    string contry;
    int n, num;
    cin >> n;
    while(n --){
        cin >> contry;
        string s;
        getline(cin, s);
        mp[contry] ++;
        // cout << s;
    }
    for(map<string, int> :: iterator it=mp.begin(); it!=mp.end(); ++it)
        cout << it->first << " " << it -> second << '\n';   
}