#include <iostream>

using namespace std;

struct node{
    string s;
    int last;
};

bool edge[1000][1000];
bool used[1000][1000];
bool cityUsed[1000];
node queue[1000000];
string arr[1000], ans[1000];

int cityN(string s){
    return (s[0] - 'A') * 26 + (s[1] - 'A');
}

int trace(int idx, int &n){
    node cur = queue[idx];
    if(cur.last != -1)
        trace(cur.last, n);
    ans[n++] = cur.s;
    return n;
}

int bfs(string s, string e, int n){
    node cur, nxt;
    int i, j, k;
    queue[0].s = s;
    queue[0].last = -1;
    for(i=0, j=1; i<j; i++){
        cur = queue[i];
        if (cur.s == e){
            int ans_i = 0;
            trace(i, ans_i);
            return ans_i;
        }
        for(k=0; k<n; k++){
            nxt.s = arr[k];
            int n1 = cityN(cur.s);
            int n2 = cityN(nxt.s);
            if (edge[n1][n2] && !used[n1][n2]){
                used[n1][n2] = true;
                nxt.last = i;
                queue[j++] = nxt;
            }
        }
    }
    return -1;
}

int main(){
    int t, n, i, j, k;
    string s1, s2, s, e;
    bool first = true;
    while(cin >> t){
        n = 0;
        for(i=0; i<1000; i++){
            cityUsed[i] = false;
            for(j=0; j<1000; j++){
                edge[i][j] = false;
                used[i][j] = false;
            }
        }
        
        for(i=0; i<t; i++){
            cin >> s1 >> s2;
            int n1 = cityN(s1), n2 = cityN(s2);
            if (!cityUsed[n1])
                arr[n++] = s1;
            if (!cityUsed[n2])
                arr[n++] = s2;
            edge[n1][n2] = edge[n2][n1] = true;
            cityUsed[n1] = cityUsed[n2] = true;
        }

        cin >> s >> e;

        int ans_idx = bfs(s,e,n);
        if (!first)
            cout << "\n";
        first = false;
        if (ans_idx < 0)
            cout << "No route\n";
        else{
            for(i=0; i<ans_idx-1; i++)
                cout << ans[i] << " " << ans[i+1] << "\n";
        }
    }


}