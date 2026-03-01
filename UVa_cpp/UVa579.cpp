#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    string s;
    while(cin >> s && s != "0:00"){
        int h = 0, m = 0;
        bool f = true;
        for(int i=0; i<s.size(); ++i){
            if (s[i] == ':'){
                f = false;
                continue;
            } 
            if (f) h = h * 10 + (s[i] - '0');
            else  m = m * 10 + (s[i] - '0');
        }
        // cout << "m = " << m << " h = " << h << endl;
        double a1 = 30 * (h == 12 ? 0 : h)  + (30.0/60) * m;
        double a2 = 6 * m; 
        // cout << a1 << " | " << a2 << endl;
        cout << fixed << setprecision(3);
        if (a1 < a2) swap(a1, a2);
        if (a1 - a2 > 180) cout << (a2 + 360) - a1 << endl;
        else cout << a1 - a2 << endl;
    }
}