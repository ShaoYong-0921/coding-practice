#include <iostream>

using namespace std;

int table[100000] = {0};

int main(){

    for(int i=1; i<10000; ++i){
        int n = i, sum = 1;
    }
    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        if (table[n]) cout << table[n];
        else cout << -1;
        cout << '\n';
    }

}