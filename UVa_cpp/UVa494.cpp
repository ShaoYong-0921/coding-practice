#include <iostream>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        bool w = false;
        int cnt = 0;
        for(int i=0; i<s.size(); ++i){
            // cout << s[i];
            if(!isalpha(s[i])){
                if (w) ++ cnt;
                w = false;
                continue;
            }
            else w = true;
        }
        cout << cnt << endl;
    }
}