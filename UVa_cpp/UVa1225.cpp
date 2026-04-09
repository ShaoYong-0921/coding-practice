#include <iostream>

using namespace std;

int ans[10];

int main(){
    int n;
    cin >> n;
    while(n --){
        for(int i=0; i<10; ++i) ans[i] = 0;
        int num;
        cin >> num;
        for(int i=1; i<=num; ++i){
            int k = i;
            while(k > 0){
                // cout << "i = " << k << endl;

                // if (k == 0){
                //     ans[0] ++;
                //     break;
                // }
                ans[k%10] ++;
                k /= 10;
            }
        }

        bool first = true;
        for(int i=0; i<10; ++i){
            if (!first) cout << " ";
            first = false;
            cout << ans[i];
        }
        cout << '\n';
    }
}