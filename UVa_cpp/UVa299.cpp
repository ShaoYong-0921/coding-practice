#include <iostream>

using namespace std;

int t[55];

int main(){
    int n;
    cin >> n;
    while(n --){
        int l;
        cin >> l;
        // cout << "l = " << l << endl;
        for(int i=0; i<l; ++i) cin >> t[i];
        int cnt = 0;
        // for(int i=0; i<l; ++i) cout << t[i] << " ";

        for(int i=0; i<l-1; ++i){
            for(int j=0; j<l-1-i; ++j){
                if ( t[j] > t[j+1] ) {
                    cnt ++;
                    swap( t[j], t[j+1]);
                }
            } 
        }
        cout << "Optimal train swapping takes "<< cnt << " swaps." << endl;
    }
}