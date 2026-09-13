#include <iostream>

using namespace std;

int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int period = 280;
string zodiac[12] = {"aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn"};

bool leap(int y){
    if (y % 400 == 0) return true;
    else if (y % 100 == 0) return false;
    else if (y % 4 == 0) return true;
    else return false;
}

int main(){
    int t; cin >> t;
    int kase = 0;
    while (t --) {
        int m, d, y;
        scanf("%2d%2d%4d", &m, &d, &y);
        //cout << m << "|" << d << "|" << y << endl;
        int sum = d;
        for(int i=0; i<m-1; ++i){
            sum += month[i];
        }
        if (leap(y) && m > 2) sum ++;
        sum += period;
        //cout << sum << endl;
        if (sum > 365 + leap(y)){
            sum -= 365 + leap(y);
            y ++;
        }
        int newM = 0;

        auto count = [&] (int mon) -> int {
            if (mon == 2 && leap(y)) return month[mon] + 1;
            else return month[mon]; 
        };
        while( sum > month[newM] ){
            sum -= count(newM);
            newM ++;
        }
        cout << ++ kase << " ";
        cout << (newM + 1 < 10 ? "0" : "") << newM + 1 << "/" << (sum < 10 ? "0" : "") << sum << "/" << y << " ";
        m = newM + 1; d = sum;
        if      ((m == 1 && d >= 21) || (m == 2 && d <= 19)) cout << zodiac[0];
        else if ((m == 2 && d >= 20) || (m==3 && d <= 20)) cout << zodiac[1];
        else if ((m == 3 && d >= 21) || (m==4 && d <= 20)) cout << zodiac[2];
        else if ((m == 4 && d >= 21) || (m==5 && d <= 21)) cout << zodiac[3];
        else if ((m == 5 && d >= 22) || (m==6 && d <= 21)) cout << zodiac[4];
        else if ((m == 6 && d >= 22) || (m==7 && d <= 22)) cout << zodiac[5];
        else if ((m == 7 && d >= 23) || (m==8 && d <= 21)) cout << zodiac[6];
        else if ((m == 8 && d >= 22) || (m==9 && d <= 23)) cout << zodiac[7];
        else if ((m == 9 && d >= 24) || (m==10 && d <= 23)) cout << zodiac[8];
        else if ((m == 10 && d >= 24) || (m==11 && d <= 22)) cout << zodiac[9];
        else if ((m == 11 && d >= 23) || (m==12 && d <= 22)) cout << zodiac[10];
        else cout << zodiac[11];
        cout << endl;


    }
}