#include <iostream>

using namespace std;

long long c[205][205];

long long C(int n, int k){
    if (k == 0 || k == n) return 1;
    if (c[n][k]) return c[n][k];
    c[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % 1000000;
    return c[n][k];
}

int main(){
    int n, k;
    while(cin >> n >> k && !(k == 0 && n == 0)){
        cout << C(n + k - 1, k - 1) << endl;
    }
}