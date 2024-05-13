// 2024/5/3 AC
#include <iostream>
#include <algorithm>

using namespace std;

int tbl[128] = {0};
char ans[1000];
string letters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
string s;

void dfs(int depth){
    if (depth == s.size()){
        for(int i=0; i<s.size(); i++)
            cout << ans[i];
        cout << "\n";
        return;
    }
    for(int i=0; i<letters.size(); i++){
        if (tbl[letters[i]]){
            tbl[letters[i]] --;
            ans[depth] = letters[i];
            dfs(depth + 1);
            tbl[letters[i]] ++;
        }
    }

}

int main(){
    int n, i;
    cin >> n;
    for(i=0; i<n; i++){
        //init table
        cin >> s;
        for(int j='A'; j<='z'; j++)
            tbl[j] = 0;
        
        for(int j=0; j<s.size(); j++)
            tbl[s[j]] ++;

        // cout << "s = " << s << endl;
        dfs(0);
    }
    
}