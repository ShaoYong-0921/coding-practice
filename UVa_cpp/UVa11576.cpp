#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while(t --){
        int len, n; cin >> len >> n; 
        string last; cin >> last;
        string ans = "" + last;
        for(int i=0; i<n-1; ++i){
            string cur; cin >> cur;
            int cnt, idx;
            if (cur == last) continue;
            for(int j=0; j<len; ++j){
                cnt = idx = 0;
                while(last[j + idx] == cur[idx++]) ++ cnt;
                //cout << cnt << endl;
                if (cnt == len - j) break;
            }
            for(int j=cnt; j<len; ++j) ans += cur[j];
            last = cur;
        }
        cout << ans.size() << endl;
        //cout << ans << endl;
        //cout << "-----------\n";
    }
}