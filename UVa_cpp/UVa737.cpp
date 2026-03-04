#include <iostream>

using namespace std;

int main(){
    int t, x, y, z, n;
    int x1, x2, y1, y2, z1, z2;
    while(cin >> t && t != 0){
        bool first = true;
        bool zero = false;
        for(int i=0; i<t; ++i){
            cin >> x >> y >> z >> n;
            if (zero) continue;
            if (first){
                x1 = x;
                x2 = x + n;
                y1 = y;
                y2 = y + n;
                z1 = z;
                z2 = z + n;
                first = false;
                continue;
            }
            if (x + n < x1 || x2 < x ||
                y + n < y1 || y2 < y ||
                z + n < z1 || z2 < z ){
                zero = true;
            }
            else {
                x1 = max(x1, x);
                x2 = min(x2, x+n);
                y1 = max(y1, y);
                y2 = min(y2, y+n);
                z1 = max(z1, z);
                z2 = min(z2, z+n);
            }
            // cout << "(" << x1 << "," << x2 << ") ";
            // cout << "(" << y1 << "," << y2 << ") ";
            // cout << "(" << z1 << "," << z2 << ") \n";
        }
        if (zero) cout << 0 << endl;
        else cout << (x2 - x1) * (y2 - y1) * (z2 - z1) << endl;


    }
    

}