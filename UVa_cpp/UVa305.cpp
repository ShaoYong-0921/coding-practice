#include <iostream>

using namespace std;

int main(){
    int k;
    while( cin >> k && k != 0){
        int m = 1;
        while(true){
            bool success = true;
            int kill = (m - 1) % (2 * k);
            for(int i=0; i<k; ++i){
                if (kill < k) {
                    success = false;
                    break;
                }

                int nxt = (kill + m - 1) % (k*2 - 1 - i);
                kill = nxt;
                
            }
            if (success) break;
            ++ m;
        }
        cout << m  << endl;
    }
}