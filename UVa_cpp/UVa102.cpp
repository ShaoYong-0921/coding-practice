#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;



int main(){
    int b[3], g[3], c[3];
    while (cin >> b[0] >> g[0] >> c[0] >> b[1] >> g[1] >> c[1] >> b[2] >> g[2] >> c[2]){
        // cost bgc
        map<string, long long> mp;
        mp["BCG"] = b[1] + b[2] + c[0] + c[2] + g[0] + g[1];
        mp["BGC"] = b[1] + b[2] + c[0] + c[1] + g[0] + g[2];
        mp["CBG"] = b[0] + b[2] + c[1] + c[2] + g[0] + g[1];
        mp["GBC"] = b[0] + b[2] + c[0] + c[1] + g[1] + g[2];
        mp["CGB"] = b[0] + b[1] + c[1] + c[2] + g[0] + g[2];
        mp["GCB"] = b[0] + b[1] + c[0] + c[2] + g[1] + g[2];
        
        long long min = LLONG_MAX;
        for(auto i : mp){
            if (i.second < min) min = i.second;
        }
        for(auto i : mp){
            if (i.second == min){
                cout << i.first << " " << min << endl;
                break;
            }
        }

    }

}