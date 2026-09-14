#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while(t --){
        long long n; cin >> n;
        if (n == 1) { cout << 1 << '\n'; continue; }
        if (n == 0) { cout << 0 << '\n'; continue; }

        auto divide = [&](long long k) -> bool{
            for (int i=2; i<=9; ++i) if (k % i == 0) return true;
            return false;
        };

        string ans = "";
        while(divide(n)){
            for(int i=9; i>1; i--) {
                if (n % i == 0){
                    ans = (char)('0' + i ) + ans;
                    n /= i;
                    break;
                }
            }
        }
        if (n > 1) cout << -1;
        else cout << ans;
        cout << '\n';
    }
}