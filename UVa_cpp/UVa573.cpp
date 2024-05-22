#include <iostream>

using namespace std;

int main(){
    int h, d;
    double f, u;
    while(cin >> h >> u >> d >> f){
        if (h == 0 && u == 0 && d == 0 && f == 0) break;
        f /= 100.0;
        //cout <<  h << " " << u << " "<< d << " "<< f << "\n";
        bool status;
        int ans, day = 0;
        double curr = 0.0;
        double fatigue = u * f;
        while(true){
            double climb = u - (day * fatigue);
            if (climb < 0)
                climb = 0;
            curr += climb;
            // cout << "fatigue = " << fatigue * day << "\n";
            day ++;
            if (curr > h){
                // cout << "T curr = " << curr << "\n";
                status = true;
                break;
            }
            curr -= d;
            if (curr < 0){
                // cout << "F curr = " << curr << "\n";
                status = false;
                break;
            }
            // cout << "curr = " << curr << "\n";
        }
        if (status)
            cout << "success on day ";
        else
            cout << "failure on day ";
        cout << day << "\n";
    }
}