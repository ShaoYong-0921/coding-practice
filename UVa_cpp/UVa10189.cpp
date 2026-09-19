#include <iostream>
#include <cstring>

using namespace std;

char m[105][105];
char ans[105][105];

int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dr[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int main(){
    int r, c, cnt = 0;
    bool first = true;
    while(cin >> r >> c && r && c){
        string s;
        for(int i=0; i<r; ++i){
            cin >> s;
            for(int j=0; j<c; ++j) m[i][j] = s[j];
        }
        memset(ans, '0', sizeof(ans));
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j) {
                if (m[i][j] == '*'){
                    for(int k=0; k<8; ++k) {
                        int x = i + dr[k];
                        int y = j + dc[k];
                        if (0 <= x && x < r && 0 <= y && y < c) ans[x][y] ++;
                    }
                }
                // cout << m[i][j];
            }
            // cout << endl;
        }
        for(int i=0; i<r; ++i)
        for(int j=0; j<c; ++j) if (m[i][j] == '*') ans[i][j] = '*';
        if (!first) cout << '\n';
        first = false;

        cout << "Field #" << ++cnt << ":\n";
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                cout << ans[i][j];
            }
            cout << '\n';
        }

    }
}