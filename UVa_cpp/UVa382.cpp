#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cout << "PERFECTION OUTPUT\n";
    while( cin >> n && n != 0){
        vector<int> factor;
        for(int i=1; i<=n/2; ++ i){
            if ( n % i == 0 ) factor.push_back(i);
        }
        int sum = 0;
        for(auto i : factor) sum += i;
        // cout << "sum = " << sum << endl;
        cout << setw(5) << right;
        if (sum == n){
            cout << n << "  PERFECT\n";
        } 
        else if (sum < n) cout << n << "  DEFICIENT\n";
        else cout << n << "  ABUNDANT\n";
    }
    cout << "END OF OUTPUT\n";
}