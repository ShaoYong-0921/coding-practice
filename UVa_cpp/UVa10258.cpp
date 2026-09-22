#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool is_solve[105][15];
int penality[105][15];

int main(){
    int t; cin >> t; 
    string str;
    getline(cin, str);
    getline(cin, str);
    bool f = true;
    while( t -- ){
        memset(is_solve, false, sizeof(is_solve));
        memset(penality, 0, sizeof(penality));
        map<int, bool> team;
        map<int ,int> score;
        map<int, int> time;
        string s;
        while(getline(cin, s)){
            if (s.empty()) break;
            // cout << "s = " << s << endl;
            stringstream ss(s);
            int n, p, t; char c;
            ss >> n >> p >> t >> c;
            team[n] = true;
            if (c == 'C' && !is_solve[n][p]) {
                time[n] += t + penality[n][p];
                score[n] ++;
                is_solve[n][p] = true;
            }
            else if (c == 'I') penality[n][p] += 20;
            else continue;
        }

        if (!f) cout << '\n';
        f = false;
        vector<tuple<int, int, int> >ans;
        for(auto &i : team){
            int n = i.first;
            ans.push_back({-score[n], time[n], n});
            // cout << n << " " << score[n] << " " << time[n] << '\n';
        }

        sort(ans.begin(), ans.end());

        for(auto &i : ans){
            cout << get<2>(i) << " " << -get<0>(i) << " " << get<1>(i) << endl;
        }
    }

}