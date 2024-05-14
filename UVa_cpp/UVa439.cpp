//2024/05/14
#include <iostream>
#include <cstring>

using namespace std;
//           1  2  3  4  5  6  7. 8
int dx[8] = {2, 1,-1,-2,-2,-1, 1, 2};
int dy[8] = {1, 2, 2, 1,-1,-2,-2,-1};

struct node{
    int x, y, dis;
};

node queue[100];
bool used[100][100];

int bfs(int sx, int sy, int ex, int ey){
    int i, j, k;
    node cur, next;
    memset(used, 0, sizeof(used));

    queue[0].x = sx;
    queue[0].y = sy;
    queue[0].dis = 0;

    used[sx][sy] = true;
    for(i=0, j=1; i<j; i++){
        cur = queue[i];
        if (cur.x == ex && cur.y == ey)
            return cur.dis;
        for(k=0; k<8; k++){
            next = cur;
            next.x += dx[k];
            next.y += dy[k];
            next.dis ++;

            if (next.x >= 1 && next.x <= 8 && next.y >= 0 && next.y < 8){
                if (!used[next.x][next.y]){
                    used[next.x][next.y] = true;
                    queue[j] = next;
                    // cout << "(" << next.x << "," << (char)('a' + next.y) << ")\n"
                    //     << "nextDis = " << next.dis << "\n";
                    j++;
                }
            }
        }
    }
    return -1;
}

int main(){
    string s1, s2;
    int start_x, start_y, end_x, end_y;
    int dis;
    while (cin >> s1 >> s2){
        start_y = s1[0] - 'a';
        start_x = s1[1] - '0';
        end_y = s2[0] - 'a';
        end_x = s2[1] - '0';

        // cout << "start x = " << start_x << " start y = " << start_y 
        //     << "\nend x = " << end_x << " end y =" << end_y << endl;
        dis = bfs(start_x, start_y, end_x, end_y);
        cout << "To get from " << s1 << " to " << s2 << " takes " << dis << " knight moves.\n";

    }   
}