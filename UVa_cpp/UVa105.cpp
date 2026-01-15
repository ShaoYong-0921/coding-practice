#include <iostream>

using namespace std;

int ans[10005] = {0};

int main(){

    int l, h, r;

    int last = 0;
    while ( cin >> l >> h >> r ){
        for(int i=l; i<r; ++i) {
            if (ans[i] < h) ans[i] = h;
            if (r > last) last = r;
        }
    }
    
    // for(int i=0; i<30; ++i) cout << ans[i] << " ";
    // cout << endl;

    // cout << "last = " << last << endl;
    int cur_h = 0;
    for(int i=0; i<last; ++i){
        // higher
        if (abs(cur_h - ans[i]) > 0){
            cur_h = ans[i];
            cout << i << " " << cur_h << " ";
        }
    }
    // for(int i=0; i<30; ++i) cout << ans[i] << ' ';
    cout << last << " 0" <<endl;
}