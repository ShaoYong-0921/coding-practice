#include <iostream>
#include <cstring>

using namespace std;

bool queue[105][55][55];
bool spot[55][55];

// void show(int n, bool q[55][55]){
//     for(int i=0; i<n; ++ i){
//         for(int j=0; j<n; ++j){
//             if ( q[i][j] ) cout << "1";
//             else cout << "0";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

void rotate(int n, bool q[55][55]){
    bool rq[55][55];
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            rq[i][j] = q[n-1-j][i];
 
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j) q[i][j] = rq[i][j];
}

bool compare(int n,bool q[55][55]){
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j){
            if (q[i][j] != spot[i][j]) return false;
        }
    return true;
}

int main(){
    int n;
    while( cin >> n && n != 0){
        memset(spot, 0, sizeof(spot));

        int q = 0;
        int cur_x, cur_y, move, player;
        char c;

        bool duplicate = false; 
        for(int i=0; i<n*2; ++i){
            cin >> cur_x >> cur_y >> c;
            if (duplicate) continue;

            --cur_x , --cur_y;
            
            if ( c == '+' ){
                spot[cur_x][cur_y] = true;
            }
            else if ( c == '-' ){
                spot[cur_x][cur_y] = false;
            }

            // show(n, spot);

            for(int j=1; j<=q; ++j){
                for(int k=0; k<4; ++k){
                    // cout << "rotate: " << j << "\n";
                    rotate(n, queue[j]);
                    // show(n ,queue[j]);
                    if(compare(n, queue[j])){
                        duplicate = true;
                        move = i + 1, player = ((q % 2) == 0 ? 2 : 1);
                        // cout << "ture\n";
                    }
                    // else cout << "false.\n";
                }
            } 

            ++ q;
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    queue[q][j][k] = queue[q-1][j][k];
                }
            }
            queue[q][cur_x][cur_y] = spot[cur_x][cur_y];
            // cout << "copy \n"; 
            // show(n, queue[q]);
        }
        if (duplicate) cout << "Player " << player << " wins on move " << move << endl;
        else cout << "Draw\n";

    }



}