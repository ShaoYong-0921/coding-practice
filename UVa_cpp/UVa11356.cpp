#include <iostream>
#include <unordered_map>
#include <numeric>

using namespace std;

int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

bool isLeap(int y){
    if (y % 400 == 0) return true;
    else if (y % 100 == 0) return false;
    else if (y % 4 == 0) return true;
    else return false;
}

int main(){
    unordered_map<string, int> mp;
    for(int i=0; i<12; i++) mp[month[i]] = i + 1;
    int t; cin >> t;
    int kase = 0;
    while(t--){
        int y = 0, m = 0, d = 0;
        string s, mon = "";
        cin >> s;
        for(int i=0, j=0; i<s.size(); ++i){
            if (s[i] == '-') { j ++ ; continue;}
            if (j == 0){ y = y * 10 + (s[i] - '0'); }
            if (j == 1) mon += s[i];
            if (j == 2) d = d * 10 + (s[i] - '0');
        }
        m = mp[mon];

        int add; cin >> add;
        int total = d + add;
        for(int i=0; i<m-1; i++) total += day[i];
        if (isLeap(y) && m > 2) total ++;
        //cout << y << "|" << m << "|" << d << "|" << total << endl;


        while(total > 365 + isLeap(y)){
            total -= 365 + isLeap(y);
            y ++;
        }
        m = 1;
        while(total > day[m - 1]){
            if (m == 2 && total == 29 && isLeap(y)) break;
            else if (m == 2 && isLeap(y)) total -= 29;
            else total -= day[m - 1];
            m ++;
        }
        string ans = to_string(y) + "-" + month[m-1] + "-" + (total < 10 ? "0" : "") + to_string(total);
        cout << "Case " << ++ kase << ": " << ans << endl;
    }
}