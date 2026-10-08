#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    string str;
    while(cin >> str && str != "0"){
        int n = 0;
        for(auto &i : str){
            if (i == ':') break;
            else n = n * 10 + (i - '0'); 
        }
        vector<int> v;
        map<int, bool> mp;
        map<int, int>idx;
        int num;
        for(int i=0; i<n; ++i){
            cin >> num;
            mp[num] = true;
            idx[num] = i;
            v.push_back(num);
        }
        bool ans = true;
        for(int i=0; i<v.size() && ans; ++i){
            for(int j=i+1; j<v.size() && ans; ++j){
                int target = v[j] + (v[j] - v[i]);
                // cout << "i : " << v[i] << "| j: " << v[j] << endl;
                // cout << "target : " << target << endl;
                if (mp[target] && idx[target] > j) ans = false;
            }
        }
        if (ans) cout << "yes\n";
        else cout << "no\n";
    }
}