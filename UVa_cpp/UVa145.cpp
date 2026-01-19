#include <iostream>
#include <iomanip>

using namespace std;

double cost[5][3] = {
    {0.10, 0.06, 0.02}, 
    {0.25, 0.15, 0.05}, 
    {0.53, 0.33, 0.13},
    {0.87, 0.47, 0.17},
    {1.44, 0.80, 0.30}
};


int main(){
    string s;
    char c;
    int s_hour, s_min, e_hour, e_min;
    while( cin >> c >> s >> s_hour >> s_min >> e_hour >> e_min ){
        if (c == '#') break;
        int t[3] = {0};
        // cout << c << " " << s << " " << s_hour << " " << s_min << " " << e_hour << " " << e_min << '\n';
        if (s_hour * 60 + s_min >= e_hour * 60 + e_min) e_min += e_hour * 60 + 1440;
        else e_min += e_hour * 60;

        s_min += s_hour * 60;

        for(int i=s_min; i<e_min; ++i){
            int k = i; 
            k %= 1440;
            // cout << "i = " << k << endl;
            if ( 0 <= k && k < 480) ++ t[2];
            else if ( 480 <= k && k < 1080) ++ t[0];
            else if ( 1080 <= k && k < 1320) ++ t[1];
            else ++ t[2];
        }

        double sum = t[0] * cost[c - 'A'][0] + t[1] * cost[c - 'A'][1] + t[2] * cost[c - 'A'][2] ;

        // cout << "t[0] = " << t[0] << endl;
        // cout << "t[1] = " << t[1] << endl;
        // cout << "t[2] = " << t[2] << endl;
        cout << fixed << setprecision(2);

        cout << setw(10) << right << s 
             << setw(6) << right << t[0] 
             << setw(6) << right << t[1]
             << setw(6) << right << t[2] 
             << setw(3) << right << c 
             << setw(8) << right << sum << endl;
    }
}