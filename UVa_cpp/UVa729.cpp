#include <iostream>

using namespace std;

void dfs(string cur, int n, int h){
    if (h < 0 || h > n - (int)cur.size()) return; 
    if (cur.size() == n ) { 
        if (!h) cout << cur << '\n'; 
        return; 
    }
    dfs(cur + '0', n , h);
    dfs(cur + '1', n , h - 1);
}

int main(){
    int t; cin >> t;
    cin.ignore();
    string str; 
    bool first = true;
    while(t --){
        getline(cin, str);
        int n, h;
        cin >> n >> h;
        if (!first) cout << '\n'; first = false;
        dfs("", n, h);
    }
}