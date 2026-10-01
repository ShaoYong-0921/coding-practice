#include <iostream>
#include <cmath>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    int sz, p;
    while(cin >> sz >> p && !(sz == 0 && p == 0)){
        // int r = ceil(sqrt(p)), cnt = r * r - p;
        int k = ceil((sqrt((double)p) - 1) / 2) ;
        int x = k, y = k, cnt = (k*2 + 1) * (k*2 + 1) - p;
        // cout << "cnt : " << cnt << " k = " << k << endl; 
        while(cnt > 0){
            for(int i=0; i<4 && cnt; ++i){
                for(int j=0; j<k*2 && cnt; ++j){
                    x += dx[i];
                    y += dy[i];
                    cnt --;
                }
            }
        }
        cout << "Line = " << sz / 2 + 1 + y << ", column = " << sz / 2 + 1 + x  << ".\n";
    }
}