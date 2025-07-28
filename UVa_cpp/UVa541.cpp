#include <iostream>

using namespace std;

int m[105][105];
int row[105], colum[105];

int main(){
    int n ,i, j;
    while( cin >> n && n != 0){
        for(i=0; i<n; i++){
            row[i] = 0;
            colum[i] = 0;
            for(j=0; j<n; j++)
                m[i][j] = 0;
        }

        for(i=0; i<n; i++)
            for(j=0; j<n; j++) cin >> m[i][j];
        
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                row[i] += m[i][j];
                colum[i] += m[j][i];
            } 
        }

        int bit_i = 0, bit_j = 0, count_i = 0, count_j = 0;
        for(i=0; i<n; i++){
            // cout << "colum " << i << " = " << colum[i] << endl;
            // cout << "row " << i << " = " << row[i] << endl;
            if ( row[i] % 2 == 1 ){
                bit_i = i;
                ++count_i;
            }
            if ( colum[i] % 2 == 1){
                bit_j = i;
                ++ count_j;
            }
        }

        if (count_i == 0 && count_j == 0 ) cout << "OK\n";
        else if (count_i == 1 && count_j == 1)
            cout << "Change bit (" << bit_i + 1 << "," << bit_j + 1 << ")\n";
        else
            cout << "Corrupt\n";
        // cout << "=================================\n";
        


    }


}