#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    int kase = 0;
    while(t --){
        string s; cin >> s;
        cout << "Case " << ++ kase << ": ";
        char c;
        int n = 0;
        bool first = true;
        for(int i=0; i<s.size(); ++i){
            if ('A' <= s[i] && s[i] <= 'Z'){
                if (!first) {
                    for (int j=0; j<n; j++) cout << c;
                    n = 0;
                }
                first = false;
                c = s[i];
            } 
            else n = n * 10 + ( s[i] - '0' );
        }
        for (int j=0; j<n; j++) cout << c;
        cout << '\n';
    }
}