#include <iostream>

using namespace std;

bool used[100][100];
int dist[100][100];

int kx[8] = { 1, 2, 2, 1,-1,-2,-2,-1};
int ky[8] = {-2,-1, 1, 2, 2, 1,-1,-2};
int by[4] = { 2, 2,-2,-2}, ty[2];
int bx[4] = {-2, 2, 2,-2}, tx[2];
int queue[100000][2];

void show(int n){
    for(int i=1; i<2*n+1; i++){
        for(int j=1; j<2*n+1; j++){
            if (used[i][j])
                cout << "O";
            else
                cout << "X";
        }
        cout << "\n";
    } 
}

int bfs(int sx, int sy, int ex, int ey){
    int cur_x ,cur_y, nxt_x, nxt_y, dist;
    int i, j; 
    queue[0][0] = sx;
    queue[0][1] = sy;
    dist[sx][sy] = 0;
    for(i=0, j=1; i<j; i++){
        cur_x = queue[i][0];
        cur_y = queue[i][1];
        for(j=0; j<8; j++){
            int x = cur_x + kx[j];
            int y = cur_y + ky[j];
            if (0 < x && x < 2 * n &&
                0 < y && y < 2 * n &&
                used[x][y]){

            }
        }
        
    }

}

int main(){
    int n, i, j, k;
    while(cin >> n && n !=0){
        //init board
        for(i=0; i<100; i++)
            for(j=0; j<100; j++)
                used[i][j] = true;
        
        int curr_x, curr_y, obst_x, obst_y, dest_x, dest_y;
        cin >> curr_x >> curr_y;
        cin >> dest_x >> dest_y;
        //cout << "curr x = " << curr_x << " y = " << curr_y << "\n";
        //cout << "dest x = " << dest_x << " y = " << dest_y << "\n";
        while(cin >> obst_x >> obst_y && obst_x != 0 && obst_y != 0)
            used[obst_x][obst_y] = false;
        show(n);
    }
}