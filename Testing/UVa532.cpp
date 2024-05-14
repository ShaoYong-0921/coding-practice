#include <iostream>

using namespace std;

int dx[6] = {};
int dy[6] = {};
int dz[6] = {};

char maze[30][30][30];
int L, R, C;

int main(){
    int x1, x2, y1, y2, z1, z2;
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
                        x1 = k;
                        y1 = j;
                        z1 = i;
                    } else if ( c == 'E'){
                        x2 = k;
                        y2 = j;
                        y2 = i;
                    }
                    maze[i][j][k] = c;

                }
            }
        }

        cout << "x = " << x1 << " y = " << y1 << " z = " << z1 << "\n";
        
    }
}