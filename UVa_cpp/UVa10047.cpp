#include <iostream>

using namespace std;

enum color { Green, Black, Red, Blue, White };
enum direct{ W, N, E, S};
int dx[] = { 0,-1, 0, 1};
int dy[] = {-1, 0, 1, 0};

struct Node{
    int x, y;
    color c;
    direct d;
};

Node queue[200000];
char arr[30][30];
int distant[30][30][5][4];
bool used[30][30][5][4];

int m, n, sx, sy, ex, ey;

void init(){
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++){
            for(int k=0; k<5; k++){
                for(int l=0; l<4; l++){
                    used[i][j][k][l] = false;
                    distant[i][j][k][l] = 0;
                }
            }
        }
    queue[0].x = sx;
    queue[0].y = sy;
    queue[0].c = Green;
    queue[0].d = N;
    used[sx][sy][Green][N] = true;
}

void push(Node n, int i){
    queue[i].x = n.x;
    queue[i].y = n.y;
    queue[i].c = n.c;
    queue[i].d = n.d;
}

int bfs(){
    init();
    for(int i=0, j=1; i<j; i++){
        Node cur, nxt;
        cur = queue[i];

        if (arr[cur.x][cur.y] == 'T' && cur.c == Green)
            return distant[cur.x][cur.y][cur.c][cur.d];
        for(int k=0; k<3; k++){

            nxt.d = (enum direct)((cur.d + k + 3) % 4);

            if (nxt.d == cur.d){
                nxt.x += dx[nxt.d];
                nxt.y += dy[nxt.d];
                nxt.c = (enum color)((cur.c + 1) % 5);
            }
            else{
                nxt.x = cur.x;
                nxt.y = cur.y;
                nxt.c = cur.c;
            }

            if (nxt.x < 0 || nxt.x >= m || nxt.y < 0 || nxt.y >= n)
                continue;
            if (!used[nxt.x][nxt.y][nxt.c][nxt.d] && arr[nxt.x][nxt.y] != '#'){
                used[nxt.x][nxt.y][nxt.c][nxt.d] = true;
                distant[nxt.x][nxt.y][nxt.c][nxt.d] = distant[cur.x][cur.y][cur.c][cur.d] + 1;
                push(nxt, j);
                j ++;
            }
        }
    }
    return -1;
}

int main(){
    int i, j, k, count = 0;
    bool first = true;
    while(cin >> m >> n && m != 0 && n != 0){
        for(i=0; i<m; i++)
            for(j=0; j<n; j++){
                cin >> arr[i][j];
                if (arr[i][j] == 'S'){
                    sx = i;
                    sy = j;
                } else if (arr[i][j] == 'T'){
                    ex = i;
                    ey = j;
                }           
            }

        int ans = bfs();
        if (!first)
            cout << "\n";
        first = false;
        cout << "Case #" << ++count << "\n";
        if (ans < 0)
            cout << "destination not reachable\n";
        else
            cout << "minimum time = " << ans << " sec\n";
    }
    
}