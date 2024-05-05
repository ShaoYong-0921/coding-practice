#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;


int tbl[128];
char path[128];
int d, ans;
string s;

void dfs(int depth){
    int i, last;
    if (depth == s.size()){
        path[depth] = 0;
        if (d == 1)
            ans ++;
        else if ((stol(path) % d) == 0)
            ans ++;
        return;
    }

    for(i='0'; i<='9'; i++){
        if (tbl[i]){
            tbl[i] --;
            path[depth] = i;
            dfs(depth + 1);
            tbl[i] ++;
        }

    }
        
    
}

int main(){
    int t;
    // bool first;
    // clock_t start = clock_t();
    cin >> t;
    while(t != 0 && cin >> s >> d){
        t --;
        ans = 0;
        // cout << "s = " << s << " d = " << d << endl;
        for(int i='0'; i<='9'; i++)
            tbl[i] = 0;
        for(int i=0; i<s.size(); i++)
            tbl[s[i]] ++;
        dfs(0);
        cout << ans << "\n";
    }

    // cout << "total time " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
    
}