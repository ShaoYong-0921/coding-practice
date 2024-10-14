#include <iostream>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        if ( s == "0") break;
        int even = 0, odd = 0;
        for(int i=0; i<s.size(); i++){
            if (i % 2 == 0)
                even += s[i] - '0';
            else 
                odd += s[i] - '0';
        }

        if (abs(odd - even) % 11 == 0) cout << s << " is a multiple of 11.\n";
        else cout << s << " is not a multiple of 11.\n";
    }
}