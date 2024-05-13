#include <iostream>

using namespace std;
int s[20];
int rec[10];
int k;
bool used[20] = {false};

void dfs(int depth, int index){
    int i;
    // cout << "depth = " << depth << endl;
    if (depth == 6){
        cout << rec[0];
        for(i=1; i<6; i++)
            cout << " " << rec[i];
        cout << "\n";
        return;
    }
    for(i=index; i<=k-(6-depth); i++){
        if (used[i])
            continue;
        rec[depth] = s[i];
        used[i] = true;
        index = i;
        dfs(depth + 1, index);
        used[i] = false;
    }
}
// 2024/04/30 AC

int main(){
    bool first = true;
    while(cin >> k && k != 0){
        if (!first)
            cout << "\n";
        first = false;
        for(int i=0; i<k; i++)
            cin >> s[i];
        // for(i=0; i<k; i++)
        //     cout << "s[" << i << "] = " << s[i] << " \n";
        dfs(0,0);
    }

}