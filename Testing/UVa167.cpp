#include <iostream>
#include <iomanip>

using namespace std;

int point[10][10], x_path[10], y_path[10], ans = 0;

void dfs(int depth){
    if (depth == 8){
        int total = 0;
        for(int i=0; i<8; i++)
            total += point[x_path[i]][y_path[i]];
        if (ans < total)
            ans = total;

        return;
    }

    for(int i=0; i<8; i++){
        bool put = true;
        for(int j=0; j<depth; j++){
            if (y_path[j] == i){
                put = false;
                break;
            }
            if (abs(x_path[j] - depth) == abs(y_path[j] - i)){
                put = false;
                break;
            }
        }

        if (put){
            x_path[depth] = depth;
            y_path[depth] = i;
            dfs(depth + 1);
        }
    }
}

int main(){
    int i, j, k;
    cin >> k;
    while(k--){
        ans = 0;
        for(i=0; i<8; i++)
            for (j=0; j<8; j++)
                cin >> point[i][j];
        dfs(0);
        cout << setw(5) << ans << "\n";
    }
}
