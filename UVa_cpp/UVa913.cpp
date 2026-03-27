#include <iostream>

using namespace std;

int main(){
    long long n;
    while(cin >> n){
        long long layer = n / 2 + 1;
        long long sum = 0;
        // for(int i=1; i<=layer; ++i){
        //     sum += i * 2 - 1;
        // }
        sum = layer * layer;
        sum = (sum * 2 - 1) + (sum * 2 - 3) + (sum * 2 - 5);
        cout << sum << endl;
        
    }
}