#include <iostream>

using namespace std;

struct rect{
    double a, b, c, d;
};

rect r[15];

int main(){
    char ch;
    double a, b, c, d, x, y;
    int fig = 0;
    while(cin >> ch && ch != '*'){
        cin >> r[fig].a >> r[fig].b >> r[fig].c >> r[fig].d;
        ++ fig;
    }
    // cout << "fig = " << fig << endl;
    int n = 0;
    while(cin >> x >> y){
        if (x == 9999.9 && y == 9999.9) break;
        // cout << "x = " << x << " y = " << y << endl;
        bool inside = false;
        for(int i=0; i<fig; ++i){
            if (r[i].a < x && x < r[i].c && r[i].d < y && y < r[i].b){
                cout << "Point " << n + 1 << " is contained in figure " << i + 1 << endl;
                inside = true;
            }
        }
        if (!inside) cout << "Point " << n + 1 << " is not contained in any figure" << endl;
        ++ n;
    }
}