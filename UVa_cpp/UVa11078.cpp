#include <iostream>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t --){
        int ans = - (1 << 31);
        int maxium, num;
        cin >> n;
        cin >> maxium;
        for(int i=1; i<n; i++){
            cin >> num;
            // cout << num << "/" << maxium << '\n';
            if ( maxium - num > ans ) {
                ans = maxium - num;
                // cout << "ans = " << ans << "\n";
            }
            if ( num > maxium ) maxium = num;
        }
        
        cout << ans << "\n";
    }
}