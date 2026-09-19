#include <iostream>
#include <cstring>

using namespace std;

char m[200][200];

int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

bool check(string s, int i, int j, int r, int c){
    bool find;
    for(int k=0; k<8; ++k){
        find = true;
        for(int l=0; l<s.size(); ++l){
            int x = j + dc[k] * l;
            int y = i + dr[k] * l;
            if (0 <= x && x < c && 0 <= y && y < r){
                if (m[y][x] != s[l]) {
                    find = false;
                    break;
                }
            }else {
                find = false;
                break;
            }
        }
        if (find) return true;
    }
    return false;
}
int main(){
    int t; cin >> t;
    bool first = true;
    while(t --){
        if (!first) cout << '\n';
        first = false;
        int r, c; cin >> r >> c;
        for(int i=0; i<r; ++i){
            string s; cin >> s;
            for(int j=0; j<c; ++j) m[i][j] = tolower(s[j]);
        }
        int n; cin >> n;
        while(n --){
            string str; cin >> str;
            for(auto &i : str) i = tolower(i);
            bool done = false;
            for(int i=0; i<r && !done; ++i) {
                for(int j=0; j<c; ++j) {
                    // if (check(str, i, j, r, c)) cout << i << "|" << j << "find\n";
                    if (check(str, i, j, r, c)) {
                        done = true;
                        cout << i + 1 << " " << j + 1 << endl;
                        break;
                    }
                }
                // cout << endl;
            }
        }

    }
}