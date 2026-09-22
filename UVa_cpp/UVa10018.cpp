#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int t; cin >> t;
    while(t --){
        string s; cin >> s;
        string rs = s; reverse(rs.begin(), rs.end());
        int cnt = 0;
        bool first = true;
        while( s != rs || first){
            first = false;
            long long n1 = stoi(s);
            long long n2 = stoi(rs);
            string newS = to_string(n1 + n2);
            //cout << "new String:" << newS << endl;
            s = newS;
            rs = s; reverse(rs.begin(), rs.end());
            cnt ++;
        }

        cout << cnt << " " << s << endl;
    }
}