#include <iostream>
#include <cstring>

using namespace std;

struct Node{
    int x, y, dist;
};

int dx[4] = { 1,-1, 0, 0};
int dy[4] = { 0, 0, 1,-1};
int start_x[105], start_y[105];
char table[105][105];
int count = 0, m;

Node queue[10000];
bool used[105][105];

int bfs(int sx, int sy){
    int i, j, k;
    Node curr, next;

    memset(used, 0, sizeof(used));
    queue[0].x = sx;
    queue[0].y = sy;
    queue[0].dist = 0;
    used[sx][sy] = true;

    for(i=0, j=1; i<j; i++){
        curr = queue[i];
        // cout << "curr: x = " << curr.x << " y = " << curr.y << "\n"; 
        if (table[curr.x][curr.y] == '3'){
            return curr.dist;
        }
        for(k=0; k<4; k++){
            next = curr;
            next.x += dx[k];
            next.y += dy[k];
            next.dist ++;
            if (0 <= next.x && next.x < m &&
                0 <= next.y && next.y < m &&
                used[next.x][next.y] == false ){
                
                used[next.x][next.y] = true;
                queue[j] = next;
                j ++;
            }
        }
    }
    return -1;
}

int main(){
    int i, j;
    while(cin >> m){
        count = 0;
        for(i=0; i<m; i++){
            j = 0;
            string s;
            cin >> s;
            for(char c: s){
                table[i][j] = c;
                if (c == '1'){
                    start_x[count] = i;
                    start_y[count] = j;
                    count ++;
                }
                j ++;
            }
        }
        // cout << "x = " << start_x[0] << " y = " << start_y[0] << endl;
        int ans = 0;
        for(int i=0; i<count; i++){
            // cout << "start x = " << start_x[i] << " y = " << start_y[i] << "\n";
            int n = bfs(start_x[i], start_y[i]);
            if(ans < n)
                ans = n;
        }

        cout << ans << "\n";
    }
}