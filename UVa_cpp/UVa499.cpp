#include <iostream>
#include <cstring>

using namespace std;

int c[150];

int main(){
    string s;
    while(getline(cin, s)){
        memset(c, 0, sizeof(c));
        int max_v = 0;
        for(int i=0; i<s.size(); ++i){
            int n = 0;
            if (isalpha(s[i])) n = ++ c[s[i]];
            if (n > max_v) max_v = n;
            // cout << s[i] << " = " << n << endl;
        }
        for(int i='A'; i<='Z'; ++i){
            if (c[i] == max_v) cout << (char)(i);
        }
        for(int i='a'; i<='z'; ++i){
            if (c[i] == max_v) cout << (char)(i);
        }
        cout << " " << max_v << endl;
    }
}