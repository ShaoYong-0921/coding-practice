#include <iostream>

using namespace std;

int row[10][10], column[10][10], square[10][10];
int arr[10][10];

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



int main(){
    int x = 0, y = 0, i, j;
    int index = 0;
    while(cin >> arr[x][y]){
        // cout << "x = " << x << " y = " << y << "\n";
        y ++;
        if (y == 9){
            y = 0;
            x ++;
        }
        if (x == 9) x = 0;

        if (x == 0 && y == 0){
            if (!isLegal()){
                cout << "illegal ! " << "\n";
            }
            for(i=0; i<9; i++){
                for(j=0; j<9; j++)
                    cout << arr[i][j];
                cout << "\n";
            }
            cout << "\n";
        }
    
    }
        
}

    
