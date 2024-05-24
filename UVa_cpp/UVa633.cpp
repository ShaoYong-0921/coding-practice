#include <iostream>

using namespace std;

bool used[100][100];
//            1  2  1  2  3  4  5  6  7  8  1  2  3  4
int dx[14] = {0, 0, 1, 2, 2, 1,-1,-2,-2,-1,-2, 2, 2,-2};
int dy[14] = {0, 0,-2,-1, 1, 2, 2, 1,-1,-2, 2, 2,-2,-2};

int queue[20000000][2];
char status[20000000];
int dist[100][100];

int n;

void init(){
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            dist[i][j] = 0;
            used[i][j] = true;
        }
    }
}

int bfs(int sx, int sy, int ex, int ey){
    int cur_x ,cur_y, nxt_x, nxt_y;
    char cur_s, nxt_s;
    int i, j, k; 
    queue[0][0] = sx;
    queue[0][1] = sy;
    status[0] = ' ';
    dist[sx][sy] = 0;
    used[sx][sy] = false;

    for(i=0, j=1; i<j; i++){
        cur_x = queue[i][0];
        cur_y = queue[i][1];
        cur_s = status[i];

        if (cur_x == ex && cur_y == ey){
            // cout << "dist = " << dist[cur_x][cur_y] << "\n";
            return dist[cur_x][cur_y];
        }

        dx[0] = 2 * n - cur_x + 1;
        dy[0] = cur_y;
        dx[1] = cur_x;
        dy[1] = 2 * n - cur_y + 1;
        // cout << "t0 x = " << dx[0] << " y = " << dy[0] << "\n";     
        // cout << "t1 x = " << dx[1] << " y = " << dy[1] << "\n";
        for(k=0; k<14; k++){

            if( 0 <= k && k <= 1 && cur_s != 'T'){
                nxt_x = dx[k];
                nxt_y = dy[k];
                nxt_s = 'T';
            }
            else if ( 2 <= k && k <= 9 && cur_s != 'K'){
                nxt_x = cur_x + dx[k];
                nxt_y = cur_y + dy[k];
                nxt_s = 'K';
            }
            else if ( 10 <= k && k <= 13 && cur_s != 'B'){
                nxt_x = cur_x + dx[k];
                nxt_y = cur_y + dy[k];
                nxt_s = 'B';         
            }
            

            if( 0 < nxt_x && nxt_x <= 2*n &&
                0 < nxt_y && nxt_y <= 2*n){
                if (used[nxt_x][nxt_y]){

                    used[nxt_x][nxt_y] = false;
                    dist[nxt_x][nxt_y] = dist[cur_x][cur_y] + 1;

                    queue[j][0] = nxt_x;
                    queue[j][1] = nxt_y;
                    status[j] = nxt_s;
                    j ++;

                }
                else if (!used[nxt_x][nxt_y] && dist[nxt_x][nxt_y] > dist[cur_x][cur_y]){
                    dist[nxt_x][nxt_y] = dist[cur_x][cur_y] + 1;
                    queue[j][0] = nxt_x;
                    queue[j][1] = nxt_y;
                    status[j] = nxt_s;
                    j ++;
                    // cout << "here\n";
                }
            }
        }

        
    }
    // cout << "dist = " << -1 << "\n";
    return -1;
}

int main(){
    int i, j, k;
    while(cin >> n && n !=0){
        //init board
        init();
        
        int start_x, start_y, obst_x, obst_y, dest_x, dest_y;
        cin >> start_x >> start_y;

        cin >> dest_x >> dest_y;

        while(cin >> obst_x >> obst_y && obst_x != 0 && obst_y != 0)
            used[obst_x][obst_y] = false;

        int ans = bfs(start_x, start_y, dest_x, dest_y);
        if (ans < 0)
            cout << "Solution doesn't exist\n";
        else
            cout << "Result : " << ans << "\n";
    }
}