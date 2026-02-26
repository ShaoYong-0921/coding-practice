#include <iostream>

using namespace std;

int p[1000000];
string a[1000000];

int main(){
    bool first = true;
    string s;
    int n, i=0;
    double x;
    cin >> n;
    while(n --){
        if (!first) cout << endl;
        first = false;
        
        getline(cin, s);
        getline(cin, s);
        getline(cin, s);
        s += " ";

        int num = 0, idx = 0;
        bool flag = true;
        for(int i=0; i<s.size(); ++i){
            if (s[i] == ' ') {
                p[idx++] = num;
                num = 0;
            }
            else num = num *10 + (s[i] - '0');
        }

        for(int i=0; i<idx; ++i){
            cin >> a[p[i]];
        }
        
        for(int i=1; i<=idx; ++i) cout << a[i] << endl;
    }
}