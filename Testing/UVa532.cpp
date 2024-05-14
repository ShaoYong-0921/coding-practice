#include <iostream>
#include <cstring>

using namespace std;
//          
int dx[6] = {1,-1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1,-1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1,-1};
//   maze[z][y][x]
char maze[30][30][30];
bool used[30][30][30];

int L, R, C;

struct Node{
    int x, y, z, dist;
};

Node queue[100];

int bfs(Node s, Node e){
    int i, j, k;
    Node curr, next;
    memset(used, 0, sizeof(used));

    queue[0].x = s.x;
    queue[0].y = s.y;
    queue[0].dist = 0;
    used[s.z][s.y][s.z] = true;
    
    for(i=0, j=1; i<j; i++){
        curr = queue[i];
        if (curr.x == e.x && curr.y == e.y && curr.z == e.z){
            return curr.dist;
        }
        for(k=0; k<6; k++){
            next = curr;
            next.x += dx[k];
            next.y += dy[k];
            next.z += dz[k];
            next.dist ++;
            if (next.x >= 0 && next.x < C &&
                next.y >= 0 && next.y < R &&
                next.z >= 0 && next.z < L &&
                maze[next.z][next.y][next.x] != '#' &&
                used[next.z][next.y][next.x] == false){
                
                used[next.z][next.y][next.x] = true;
                queue[j] = next;
                j++;
            }
        }

    }
    return -1;
}

int main(){
    Node start, end; 
    while(cin >> L >> R >> C){
        // cout << L << " " << R << " " << C << "\n";
        if (L == 0 && R == 0 && C == 0)
            break;

        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                for(int k=0; k<C; k++){
                    char c;
                    cin >> c;
                    if (c == 'S'){
                        start.x = k;
                        start.y = j;
                        start.z = i;

                    } else if ( c == 'E'){
                        end.x = k;
                        end.y = j;
                        end.z = i;
                    }
                    maze[i][j][k] = c;

                }
            }
        }

        // cout << "x = " << start.x << " y = " << start.y << " z = " << start.z << "\n";
        int ans = bfs(start, end);
        if (ans >= 0)
            cout << "Escaped in " << ans << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }
}