#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct node{
    string s;
    int dis, last;
};

string dir[25200];
node queue[25200];

map <string , vector<string>> mp;

int bfs(string s1, string s2){
    // cout << "bfs: s1 = " << s1 << " s2 = " << s2 << '\n';
    // for(auto &i : mp[s1]) cout << s1 << "->" << i << "\n";
    // for(auto &i : mp[s2]) cout << s2 << "->" << i << "\n";

    map<string, map<string, bool> > used;
    queue[0].s = s1;
    queue[0].dis = 0;
    queue[0].last = -1;
    node cur;
    for(int i=0, j=1; i<j; i++){
        cur = queue[i];
        if (queue[i].s == s2) return i;
        for(auto &k : mp[cur.s]){
            if (!used[cur.s][k]){
                used[cur.s][k] = true;
                queue[j].s = k;
                queue[j].dis = cur.dis + 1;
                queue[j].last = i;
                j++;

            }
        }
    }
    return -1;
}

void trace(int idx){
    node cur = queue[idx];
    if (cur.last != -1)
        trace(cur.last);
    cout << cur.s << "\n";
}

int main(){
    string s;
    int idx = 0;
    
    while( getline( cin, s) && s != ""){
        // cout << s;
        dir[idx] = s;
        idx ++; 
    }
    // for(int i=0; i<idx; i++)
    //     cout << dir[i] <<'\n';
    for(int i=0; i<idx; i++){
        for(int j=i+1; j<idx; j++){
            if (dir[i].size() != dir[j].size()) continue;
            int diff = 0;
            for(int k=0; k<dir[i].size(); k++){
                if (dir[i][k] != dir[j][k]) diff ++;
            }
            // cout << "s1 = " << dir[i] << "\ns2 = " << dir[j] << " diff = " << diff << '\n';
            if (diff == 1){
                mp[dir[i]].push_back(dir[j]);
                mp[dir[j]].push_back(dir[i]);
            }
        }
    }
    bool first = true;
    string start = "", end = "";
    while( cin >> start >> end){
        // cout << start << "|" << end << '\n';
        if (first == false) cout << '\n';
        if (start.size() != end.size()){
            cout << "No solution.\n";
        }
        else{
            int ans;
            ans = bfs(start, end);
            if (ans == -1){
                cout << "No solution.\n";
            }
            else 
                trace(ans);
            // cout << "ans = " << ans << endl;
        }
        first = false;
        // printf("%s, %s \n", start.c_str(), end.c_str());
    }
}