#include <iostream>

using namespace std;

int main(){
    string s;
    bool change = false;
    while(getline(cin, s)){
        for(int i=0; i<s.size(); i++){
            if (s[i] == '"') {
                if (change) {
                    cout << "''";
                    change = false;
                }
                else {
                    cout << "``";
                    change = true;
                }
            }
            else
                cout << s[i];
        }
        cout << '\n';
    }
}