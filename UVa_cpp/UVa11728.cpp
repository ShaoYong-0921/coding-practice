#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int ans[100000];

int main(){
    memset(ans, -1, sizeof(ans));
    for(int i=1; i<=1000; i++){
        vector<int> factor({i});
        for(int j=1; j<i/2+1; j++){
            if (i % j == 0) factor.push_back(j);
            else continue;
        }
        int sum = 0;
        //cout << "i = " << i << endl;
        for(auto &k : factor) {
            // cout << k << " ";
            sum += k;
        }
        // cout << "sum = " << sum << endl;
        ans[sum] = i;
    }
    int n, kase = 0;
    while(cin >> n && n){
        cout << "Case " << ++ kase << ": "<< ans[n] << endl;
    }
}