#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int t; cin >> t;
    while (t --){
        int h, m;
        scanf("%d:%d", &h, &m);
        auto convert = [&](int h, int m) -> string {
            string s;
            if (!h) s = to_string(m);
            else s = to_string(h) + ( m < 10 ? "0" : "") + to_string(m);
            return s;
        };

        int ans_h, ans_m;
        while(true){
            m ++;
            if (m >= 60) { m = 0; h ++; }
            if (h >= 24) { h = 0; }
            string str = convert(h, m);
            //cout << str << endl;
            bool palind = true;
            for(int i=0; i<str.size()/2; ++i){
                if (str[i] != str[str.size()-1-i]) palind = false;
            }
            if (palind){
                ans_h = h; ans_m = m;
                break;
            }
        }
        cout << (ans_h < 10 ? "0" : "") << ans_h << ":" << (ans_m < 10 ? "0" : "") << ans_m << endl;
    }
}