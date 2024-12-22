#include <iostream>

using namespace std;

char graph[55][55];
int tail[55];
int maxium, minium, cur;

char sybol(char c){
    if (c == 'R') return '/';
    else if (c == 'F') return '\\';
    else if (c == 'C') return '_';
    return ' ';
}

void print(int x, int y){
    int range=0;
    for(int i=y; i>=x; i--){
        if (tail[i] > range) range = tail[i];
        cout << "| ";
        for(int j=0; j<=tail[i]; j++){
            cout << graph[j][i];
        }
        cout << '\n';
    }
    cout << "+-";
    for(int i=0; i<=range+1; i++) cout << '-';
    cout << "\n\n";
}


int main(){
    int n, cnt = 1;
    cin >> n;
    while(n --){
        cout << "Case #" << cnt++ << ":\n";
        for(int i=0; i<55; i++) tail[i] = 0;
        for(int i=0; i<55; i++)
            for(int j=0; j<55; j++)
                graph[i][j] = ' ';
        string s;
        cin >> s;
        maxium = 0, minium = 100, cur = 0;
        for(int i=1; i<=s.size(); i++){
            if (cur > maxium) maxium = cur;
            if (cur < minium) minium = cur;
            if (s[i-1] == 'R' && s[i] != 'F') cur ++;
            if (s[i-1] == 'F' && s[i] == 'F' ||
                s[i-1] == 'C' && s[i] == 'F') cur --;
        }
        // printf("max: %d, min: %d\n", maxium, minium);

        int x = 0, y = abs(minium);
        maxium += abs(minium);
        minium += abs(minium);
        graph[x][y] = sybol(s[0]);
        for(int i=1; i<s.size(); i++){
            if (s[i-1] == 'R') {
                if (s[i] == 'F') graph[++x][y] = sybol(s[i]);
                else graph[++x][++y] = sybol(s[i]);
            }
            if (s[i-1] == 'F') {
                if (s[i] == 'R' || s[i] == 'C') graph[++x][y] = sybol(s[i]);
                else graph[++x][(--y)] = sybol(s[i]);
            }
            if (s[i-1] == 'C') {
                if (s[i] == 'F') graph[++x][--y] = sybol(s[i]);
                else graph[++x][y] = sybol(s[i]);
            }
            tail[y] = x;
            // print(s.size(), maxium);
        }
        print(minium, maxium);
    }
}