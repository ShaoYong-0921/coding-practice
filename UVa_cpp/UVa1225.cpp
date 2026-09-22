#include <iostream>
#include <cstring>

using namespace std;

int ans[10];

int main(){
    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        memset(ans, 0, sizeof(ans));
        int tmp = n;
        while( n > 0 ){
            string s = to_string(n);
            // cout << s << endl;
            for(auto &i : s) ans[i - '0'] ++;
            n --;
        }
        for(int i=0; i<10; ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << '\n';
    }
}