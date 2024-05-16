#include <iostream>

using namespace std;

int m;

struct Node{
    int x, y; 
    int dist;
};

Node queue[10005];

int dx[4] = { 1,-1, 0, 0};
int dy[4] = { 0, 0, 1, -1};

int start_x[105], start_y[105];
char table[105][105];
bool used[105][105];


int bfs(int sx, int sy){
    Node curr, next;

    for(int i=0; i<105; i++)
        for(int j=0; j<105; j++)
            used[i][j] = false;

    queue[0].x = sx;
    queue[0].y = sy;
    queue[0].dist = 0;
    used[sx][sy] = true;

    for(int i=0, j=1; i<j; i++){
        curr = queue[i];
        if (table[curr.x][curr.y] == '3'){
            return curr.dist;
        }
        for(int k=0; k<4; k++){
            next = curr;
            next.x += dx[k];
            next.y += dy[k];

            if(next.x < 0 || next.x >= m || next.y < 0 || next.y >= m) continue;
            if (!used[next.x][next.y]){
                
                used[next.x][next.y] = true;
                next.dist ++;
                queue[j] = next;
                j ++;
            }
        }
    }
    return 0;
}

int main(){
    int ans, count, n;
    while(cin >> m){
        ans = count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                cin >> table[i][j];
                if (table[i][j] == '1'){
                    start_x[count] = i;
                    start_y[count] = j;
                    count ++;
                }
            }
        }

        for(int i=0; i<count; i++){
            n = bfs(start_x[i], start_y[i]);
            ans = max(ans, n);
        }

        cout << ans << "\n";
    }
    return 0;
}