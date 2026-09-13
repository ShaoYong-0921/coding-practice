#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

double w[4] = {12.01, 1.008, 16.0, 14.01};
char A[4] = {'C', 'H', 'O', 'N'};

int main(){
    map<char, double> mp;
    for(int i=0; i<4; ++i) mp[A[i]] = w[i];
    int t; cin >> t;
    while(t--){
        string s;
        char cur = ' ', last = ' '; 
        int n = 0;
        double sum = 0.0;
        cin >> s;
        cout << fixed << setprecision(3);
        for(auto &i : s){
            if ( '0' <= i && i <= '9') n = n * 10 + i - '0';
            else {
                cur = i;
                if (last != ' ') {
                    sum += (n == 0 ? 1 : n) * mp[last];
                    //cout << "sum = " << sum << endl;
                    n = 0;
                }
            }
            last = cur;
        }
        sum += (n == 0 ? 1 : n) * mp[cur];
        cout << sum << endl;
    }

}