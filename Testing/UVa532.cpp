#include <iostream>

using namespace std;
//          
int dx[6] = {1,-1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1,-1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1,-1};
//   maze[z][y][x]
char maze[30][30][30];
int L, R, C;

struct Node{
    int x, y, z, dst;
};

int bfs(Node s, Node e){
    Node cur
    if ()
}

int main(){
    Node start, end; 
    while(cin >> L >> R >> C){
        cout << L << " " << R << " " << C << "\n";
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
                        cout << "S";
                    } else if ( c == 'E'){
                        end.x = k;
                        end.y = j;
                        end.z = i;
                    }
                    maze[i][j][k] = c;

                }
            }
        }

        cout << "x = " << start.x << " y = " << start.y << " z = " << start.z << "\n";
        
    }
}