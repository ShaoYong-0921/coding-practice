#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int arr[256];
int len[40];

int main(){
    int n, kase = 0;
    while(cin >> n){
        int ans = 0;
        while(n --){
            memset(arr, 0, sizeof(arr));
            memset(len, 0, sizeof(len));
            string s; cin >> s;
            int letter = 0;
            for(auto &i: s) {
                if (!arr[i]) letter ++;
                arr[i] ++;
            }
            bool is_ans = true;
            for(int i='a'; i<='z'; ++i){
                if (!arr[i]) continue;
                if ( ++len[arr[i]] >= 2 ) is_ans = false;
            }
            if (is_ans && letter >= 2) ans ++;
        }
        cout << "Case " << ++kase << ": " << ans << '\n';
    }
}