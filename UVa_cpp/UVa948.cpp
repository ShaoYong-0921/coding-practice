#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t; cin >> t;
    int n1 = 1 , n2 = 1, sum = 0;
    vector<int> v;
    v.push_back(1);
    while(sum <= 1000000000){
        sum = n1 + n2;
        //cout << sum << " ";
        v.push_back(sum);
        n2 = n1;
        n1 = sum;
    }
    // cout << endl;
    reverse(v.begin(), v.end());
    while( t -- ){
        int n ; cin >> n;
        cout << n << " = ";
        bool f = false;
        string ans = "";
        if (!n) ans = "0";
        for(int i=0; i<v.size(); ++i){
            if (n /v[i]) f = true;
            if (f){
                ans += '0' + n / v[i];
            }
            n = n % v[i];
        }
        cout << ans << " (fib)\n";
    }

}