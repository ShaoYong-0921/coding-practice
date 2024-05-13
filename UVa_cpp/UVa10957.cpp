//2024/5/14 AC
#include <iostream>

using namespace std;

int row[10][10], column[10][10], square[10][10];
int arr[10][10], ept_x[100], ept_y[100];
int space = 0, ans = 0;

bool isLegal(){
    int i, j;
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            row[i][j] = column[i][j] = square[i][j] = 0;

    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            row[i][arr[i][j]] ++;
            column[j][arr[i][j]] ++;
            square[(i/3)*3 + (j/3)][arr[i][j]] ++;
            // cout << (i/3)*3 + (j/3);
        }
    }

    bool legal = true;
    for(i=0; i<9; i++){
        for(j=1; j<10; j++){
            // cout << "arr[" << i << "][" << j << "] = " << row[i][j] << "\n";
            if (row[i][j] > 1 || column[i][j] > 1 || square[i][j] > 1){
                // cout << "i = " << i << " j = " << j << "\n";
                return false;
            }
        }
    }
    return true;

    // for(int i=0; i<10; i++){
    //     for(int j=0; j<10; j++)
    //         cout << row[i][j];
    //     cout << "\n";
    // }
    // cout << "\n";
}

void dfs(int depth){
    int i, j;
    if (depth == space){
        // cout << "arrive !\n" ;
        ans ++;
        return;
    }

    int x = ept_x[depth], y = ept_y[depth];
    // cout << "x = " << x << " y = " << y << " depth = " << depth << "\n";
    for(j=1; j<=9; j++){
        if (ans > 1)
            return;
        if (row[x][j] > 0 || column[y][j] > 0 || square[3*(x/3)+(y/3)][j] > 0)
            continue;
        row[x][j] ++;
        column[y][j] ++;
        square[3*(x/3)+(y/3)][j] ++;

        dfs(depth + 1);

        row[x][j] --;
        column[y][j] --;
        square[3*(x/3)+(y/3)][j] --;
    }
    
}



int main(){
    int count = 0, x = 0, y = 0, i, j;
    
    while(cin >> arr[x][y]){
        // cout << "x = " << x << " y = " << y << "\n";
        if (arr[x][y] == 0) {
            ept_x[space] = x;
            ept_y[space] = y;
            space ++;
        }
        y ++;
        if (y == 9){
            y = 0;
            x ++;
        }
        if (x == 9) x = 0;

        if (x == 0 && y == 0){
            cout << "Case " << ++count << ": "; 
            if (!isLegal()){
                cout << "Illegal.\n";
                space = 0;
                ans = 0;
                continue;
            }

            // cout << "space = " << space << "\n";
            dfs(0);
            if (ans == 1)
                cout << "Unique.\n";
            else if (ans > 1)
                cout << "Ambiguous.\n";
            else
                cout << "Impossible.\n";
            // cout << "ans = " << ans << "\n";

            space = 0;
            ans = 0;

        }
    
    }
        
}

