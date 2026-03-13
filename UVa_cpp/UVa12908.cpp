#include <iostream>
#include <algorithm>
// #include <cstring>

using namespace std;

int a[20000];

// static auto fast_io = []
// {
//     ios::sync_with_stdio(false);
//     cout.tie(nullptr);
//     cin.tie(nullptr);
//     return 0;
// }();
    
int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    long long n = 0, k = 0;
    // memset(a, 0, sizeof(a));
    while( k < 100000000){
        k += n + 1;
        a[n] = k;
        ++ n;
    }
    // cout << "n = " << n << endl;

    long long s;
    while(cin >> s){
        if (!s) break;
        auto ub = upper_bound(a, a+n, s);
        int idx = ub - a;
        // cout << "upper bound: " << idx << " | " << a[idx] << endl; 
        cout << a[idx] - s << " " << idx + 1 << '\n';         
    }
}