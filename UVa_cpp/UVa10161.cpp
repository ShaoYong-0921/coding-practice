#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n; 
    while(cin >> n && n){
        int r = ceil(sqrt(n));
        // cout << "r = " << r << endl;
        int x, y;
        
        int cnt = n - (r - 1) *( r - 1);
        //cout << "cnt = " << cnt << endl;
        if (r % 2){
            x = (cnt > r ? r - (cnt - r) : r);
            y = (cnt > r ? r : cnt);
        }
        else {
            y = (cnt > r ? r - (cnt - r) : r);
            x = (cnt > r ? r : cnt);
        }
        cout << x << " " << y << endl;
    }

}