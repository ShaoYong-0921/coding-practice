#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

char print(char c){
    if (c == 'R') return '/';
    else if (c == 'F') return '\\';
    else return '_';
}

int main(){
    int t; cin >> t;
    while(t --){
        string s; cin >> s;
        vector<int> v = {0};
        map<int, int> mp;
        mp[0] ++;
        int y = 0;
        char last = 'C';
        for(auto i : s) {
            if (i == 'R') y ++;
            else if (i == 'F') y --;
            v.push_back(y);
            if (last == 'C' && i == 'R') mp[y-1] ++;
            else if (last == 'C' && i == 'F') mp[y+1] ++;
            else mp[y] ++;
            last = i;
        }
        
        for(auto i : v ) cout << i << " ";
        cout << endl;
        int max = *max_element(v.begin(), v.end());
        int min = *min_element(v.begin(), v.end());
        // int l = v.size();
        for(int i=max; i>=min; --i){
            int l = 0;
            cout << i << "|";
            cout << mp[i];
            // while(mp[i]){
            //     if (v[l] == i) {
            //         cout << print(s[l]);
            //         mp[i] --;
            //     }
            //     else cout << " ";
            // }
            cout << '\n';
        }
    }
}
