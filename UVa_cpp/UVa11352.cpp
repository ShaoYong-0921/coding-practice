#include <iostream>
#include <cstring>

using namespace std;

bool arr[105][105];
char table[105][105];

int k_dx[8] = { 1, 1, 1, 0, 0,-1,-1,-1};
int k_dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

int dx[8] = {2, 1,-1,-2,-2,-1, 1, 2};
int dy[8] = {1, 2, 2, 1,-1,-2,-2,-1};

int queue[50000][2], dist[5000][5000];
int N, M, T;
int bfs(int sx, int sy, int ex, int ey){
    int curr_x, curr_y, next_x, next_y;
    queue[0][0] = sx;
    queue[0][1] = sy;
    dist[sx][sy] = 0;
    for(int i=0, j=1; i<j; i++){
        curr_x = queue[i][0];
        curr_y = queue[i][1];
        for(int k=0; k<8; k++){
            next_x = curr_x + k_dx[k];
            next_y = curr_y + k_dy[k];
            if( 0 <= next_x && next_x < N &&
                0 <= next_y && next_y < M && 
                arr[next_x][next_y] == true){
                
                // cout << "next x = "  << next_x << " y = " << next_y << "\n";
                arr[next_x][next_y] = false;
                queue[j][0] = next_x;
                queue[j][1] = next_y;
                dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
                j ++;

                if (next_x == ex && next_y == ey)
                    return dist[next_x][next_y];
            }

        }
    }
    return -1;
}

int main(){
    int i, j, k, l;
    int start_x, start_y, end_x, end_y;
    cin >> T;
    for(i=0; i<T; i++){
        memset(arr, 1, sizeof(arr));
        cin >> N >> M;
        for(j=0; j<N; j++){
            for(k=0; k<M; k++){
                char c;
                cin >> c;
                table[j][k] = c;
                if (c == 'Z'){
                    // cout << "j = " << j << " k = " << k << "\n";
                    arr[j][k] = false;
                    for(l=0; l<8; l++){
                        int x = j + dx[l];
                        int y = k + dy[l];
                        // cout << "x = " << x << " y = " << y << "\n";
                        if (0 <= x && x < N && 0 <= y && y < M){
                            arr[x][y] = false;
                        }
                    }
                }
                else if (c == 'A'){
                    arr[j][k] = false;    
                    start_x = j; 
                    start_y = k;
                }
                else if (c == 'B'){
                    arr[j][k] = false;    
                    end_x = j; 
                    end_y = k;
                }
            }
        }
        arr[end_x][end_y] = true;
        int ans = bfs(start_x, start_y, end_x, end_y);
        if (ans == -1)
            cout << "King Peter, you can't go now!\n";
        else
            cout << "Minimal possible length of a trip is " << ans << "\n";

    }

}