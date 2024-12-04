#include <iostream>
#include <cmath>

using namespace std;

int s[1005];

void sumfactors(){
    for(int i=0; i<=1005; i++) s[i] = -1;
    s[1] = 1;
    for(int i=2; i<=1000; i++){
        int sum = i;
        for(int j=1; j<=i/2; j++){
            if (i % j == 0) {
                // cout << "+ " << j << '\n';
                sum += j;
                if (sum > 1000) break;
            }
        }
        if (sum > 1000) continue;
        s[sum] = i;
        // cout << i << ": sum = " << sum << endl;
    }
    return;
}

int main(){
    sumfactors();
    int n, count = 1;
    while(cin >> n && n != 0){
        cout << "Case " << count++ << ": " << s[n] << '\n';
    }
}