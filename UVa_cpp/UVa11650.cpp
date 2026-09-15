#include <iostream>
// #include <cstdio>

using namespace std;

int main(){
    int n; cin >> n;
    while(n --){
        int h, m;
        scanf("%d:%d", &h, &m);
        //cout << h << "|" << m << endl;
        int ans_h;
        if (m == 0) ans_h = ( h == 12 ? 12 : 12 - h) ;
        else ans_h = (h == 12 ? 11 : 11 - h);
        cout << (ans_h < 10  && ans_h != 0 ? "0" : "") << (ans_h == 0 ? 12 : ans_h);
        cout << ":";
        int min = 60 - m;
        cout << (60 - m < 10 || m == 0 ? "0" : "" ) << ( m == 0 ? 0 : 60 - m) << endl;
    }
}