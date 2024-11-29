#include <iostream>

using namespace std;

string str = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main(){
    int n;
    string s;
    // cin >> n;
    // getline(cin, s);
    while(getline(cin, s)){
        // getline(cin, s);
        for(int i=0; i<s.size(); i++){
            if ('A' <= s[i] && s[i] <= 'Z') s[i] += 'a' - 'A';
            // cout << (char)s[i] << '\n';
            if (s[i] == ' '){
                cout << ' ';
                continue;
            }
            for(int j=0; j<str.size(); j++){
                if ((char)s[i] == str[j])
                    cout << (str[j-2]);
            }
        }
        cout << '\n';
    }
}