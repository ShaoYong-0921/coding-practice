#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        cout << "TERM " << n << " IS ";
        int cnt = 0;
        bool find = false;

        for(int i=1; i<1000000; ++i){
            int k = 1;
            if (find) break;

            for(int j=i; j>=1; --j){
                ++cnt;

                if (cnt == n) {
                    find = true;
                    if (i % 2 == 0) cout << k << "/" << j << endl;
                    else cout << j << "/" << k << endl;
                    break;
                }
                ++ k;
            }
        }
    }
}