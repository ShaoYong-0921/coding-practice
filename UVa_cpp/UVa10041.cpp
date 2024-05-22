#include <iostream>
#include <algorithm>

using namespace std;

int relate[3000];

int main(){
    int t, n, i, j;
    cin >> t;
    for(i=0; i<t; i++){
        cin >> n;
        for(j=0; j<n; j++){
            cin >> relate[j];
        }
        sort(relate, relate+n);
        int mid = relate[n/2];
        int ans = 0;
        for(j=0; j<n; j++){
            ans += abs(mid - relate[j]);
        }
        cout << ans << "\n";
    }
}