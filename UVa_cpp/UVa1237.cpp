#include <iostream>
#include <sstream>

using namespace std;

struct m{
    string n = "";
    int h = 0, l = 0;
};
SAAAfff ASSDD
m manu[20000];

int main(){
    int t, d, q;
    cin >> t;
    bool first = true;
    while( t -- ){
        if (!first) cout << '\n';
        first = false;
        cin >> d;
        string s;
        getline(cin, s);
        for(int i=0; i<d; ++i){
            getline(cin, s);
            stringstream ss(s);
            ss >> manu[i].n >> manu[i].l >> manu[i].h;
            // cout << manu[i].n << " " <<  manu[i].l << " " <<  manu[i].h << endl;
        } 
        cin >> q;
        while(q --){
            int price;
            cin >> price;
            bool f = true;
            string ans = "";
            for(int i=0; i<d; ++i){
                if (manu[i].l <= price && price <= manu[i].h){
                    if (ans != ""){
                        f = true;
                        break;
                    }
                    ans = manu[i].n;
                    f = false;
                }
            }
            if (f) cout << "UNDETERMINED\n";
            else cout << ans << endl;
        }

    } 
}i