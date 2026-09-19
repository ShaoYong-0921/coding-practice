#include <iostream>

using namespace std;

int main(){
    string s;
    string ans = "";
    bool f;
    while(cin >> s && s!= "~"){
        if (s == "#"){
            int sum = 0;
            for(auto i: ans){
                sum = sum * 2 + (i - '0');
            }
            cout << sum << '\n';
            ans = "";
        } 
        int n = s.size();
        if (n == 1) f = 1;
        else if( n == 2) f = 0;
        else {
            n -= 2;
            while(n --){
                if(f) ans += "1";
                else ans += "0";
            }
        }
    }
}