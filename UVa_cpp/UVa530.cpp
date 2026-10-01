#include <iostream>
#include <algorithm>

using namespace std;

long long C(int n, int k){
    long long sum = 1;
    for(int i=1; i<=k; ++i) sum = sum * (n - k + i) / i;
    return sum;
}

int main(){
    int n, k;
    while(cin >> n >> k && (n != 0 || k != 0)){
        cout << C(n, min(k,n-k)) << endl;
    }
}