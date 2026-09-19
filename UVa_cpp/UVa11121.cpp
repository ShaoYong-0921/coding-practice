#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t; cin >> t;
    for(int i=0; i<t; ++i) {
        int n; cin >> n;
        string ans = "";
        cout << "Case #" << i + 1 << ": ";
        if (n == 0) { cout << "0\n"; continue; }
        while( n != 0 ){
            int r = n % -2;
            int q = n / -2;
            if ( r < 0 ) {
                q ++; 
                r += 2;
            }
            ans += '0' + r;
            n = q;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}