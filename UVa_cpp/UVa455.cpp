#include <iostream>

using namespace std;

int main(){
    int n;
    string s;
    bool first = true;
    cin >> n;
    while( n-- ){
        getline(cin , s);
        cin >> s;
        int len = 1, ans = s.size();
        bool pass;
        for(int len=1; len<=s.size()/2; ++len){
            pass = true;
            if (s.size() % len != 0) continue;
            for(int i=0; i<s.size(); ++ i){
                // cout << "i = " << i << " | " << "len = " << len << endl;
                // cout << "s[i%len] = " << s[i%len]  << " | s[i] = " << s[i] << endl;
                if( s[i%len] != s[i]){
                    pass = false;
                    break;
                }
            }
            if (pass) {
                ans = len;
                break;
            }
        }
        if (!first) cout << endl;
        if (pass) cout << ans << endl;
        else cout << s.size() << endl;
        first = false;
    }
}