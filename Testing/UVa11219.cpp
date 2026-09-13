#include <iostream>

using namespace std;

int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool leap(int y){
    if (y % 400 == 0) return true;
    else if (y % 100 == 0) return false;
    else if (y % 4 == 0) return true;
    else return false;
}

int main(){
    int t; cin >> t;
    int kase = 0;
    while(t--){
        int n, d1, m1, y1, d2, m2, y2;
        // scanf("%d", &n);
        scanf("%2d/%2d/%4d", &d1, &m1, &y1);
        scanf("%2d/%2d/%4d", &d2, &m2, &y2);
       // cout << d2 << " " << m2 << " " << y2 << endl;
        cout << "Case #" << ++kase << ": ";
    }
}