#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int n;
    while( cin >> n && n){
        vector<int> v;
        int num;
        for(int i=0; i<n; ++i) {cin >> num; v.push_back(num);}
        int pair = 0, common = 0;
        for(int i=0; i<v.size(); ++i){
            for(int j=i+1; j<v.size(); ++j){
                pair ++;
                //cout << v[i] << "-" << v[j] << endl;
                if (__gcd(v[i], v[j]) == 1) common ++;
            }
        }
        
        cout << fixed << setprecision(6);
        //cout << pair << "|" << common << endl;
        if (common == 0) cout << "No estimate for this data set.\n";
        else cout << sqrt( 6.0 / common * pair) << '\n';
    }
}