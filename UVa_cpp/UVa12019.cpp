#include <iostream>
#include <algorithm>

using namespace std;

int m[12] = {10, 21, 28, 4, 9, 6, 11, 8, 5, 10, 7, 12};
string s[7] = { "Monday", "Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int main(){
    int n;
    cin >> n;
    while(n --){
        int month, day, week;
        cin >> month >> day;
        week = (day - m[month-1]) % 7;
        if (week < 0) week += 7;
        // cout << week << '\n';
        cout << s[week] << '\n';
    }
}