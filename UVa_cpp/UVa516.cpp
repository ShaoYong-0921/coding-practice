#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;

bool prime[1000000];

int main(){
    memset(prime, true, sizeof(prime));
    prime[0] = false; prime[1] = false;
    for(int i=2; i<100000; ++i) {
        for(int j=i+i; j<100000; j+=i) prime[j] = false;
    }
    vector<int> v;
    for(int i=2; i<40000; ++i) if (prime[i]) v.push_back(i);
    // cout << v.size() << endl;
    string s;
    bool first = true;
    while(getline(cin, s) && s != "0"){
        stringstream ss(s);
        int n, e, sum = 1;
        while (ss >> n >> e) sum *= pow(n, e);
        //cout << sum << endl;
        sum --;
        //if (!first) cout << '\n'; first = false;
        bool f = true;
        for(int i=v.size()-1; i>=0; --i){
            if (sum >= v[i] && sum % v[i] == 0) {
                int cnt = 0;
                while(sum % v[i] == 0){
                    //cout << "sum :" << sum << endl;
                    sum /= v[i];
                    cnt ++;
                }
                if (!f) cout << " "; 
                f = false;
                cout << v[i] << " " << cnt;
            }
        }
        cout << '\n';
    }
    
}