#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool prime[1000005];

void creatTable(){
    memset(prime, 1, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i<1000000; ++i){
        for(int j=i+i; j<1000000; j+=i) prime[j] = false;
    }
}

int main(){
    creatTable();
    vector<int> v;
    for(int i=0; i<1000000; i++) if (prime[i]) v.push_back(i);
    int n;
    while(cin >> n && n){
        int ans = 0;
        for(int i=0; i<v.size(); ++i){
            if (v[i] > n ) break;
            if (n % v[i] == 0) ans ++;
        }
        cout << n << " : "<< ans << endl;
    }
}