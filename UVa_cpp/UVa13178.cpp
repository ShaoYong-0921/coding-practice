#include<iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        n = (1 + n) * n /2;
        if (n % 3 == 0) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}