#include <iostream>

using namespace std;

enum direct{N, E, S, W};

bool lost[60][60];

string now(direct d){
    if ( d == N ) return "N";
    else if ( d == E) return "E";
    else if ( d == S) return "S";
    else return "W"; 
}

void f(int& x, int& y, direct d){
    if ( d == N ) y ++;
    else if ( d == S) y --;
    else if ( d == E) x ++;
    else x --;  
}

int main(){
    int positx, posity, x, y;
    char c;
    direct d;
    string s;
    for(int i=0; i<60; i++)
        for(int j=0; j<60; j++)
            lost[i][j] = false;
    
    cin >> positx >> posity;
    while( cin >> x >> y >> c){
        if ( c == 'N' ) d = N;
        else if ( c == 'E') d = E;
        else if ( c == 'S')  d = S;
        else if ( c == 'W') d = W;
        // cout << "current:" << now(d) << '\n';
        cin >> s;
        bool isLost = false;
        for(int i=0; i<s.size(); i++){
            if (s[i] == 'F'){
                int nxt_x = x , nxt_y = y;  
                f(nxt_x, nxt_y, d);
                if ( (nxt_x < 0 || nxt_x > positx || nxt_y < 0 || nxt_y > posity) && lost[x][y])
                    continue;
                if (nxt_x < 0 || nxt_x > positx || nxt_y < 0 || nxt_y > posity){
                    lost[x][y] = true;
                    isLost = true;
                    break;
                }
                x = nxt_x;
                y = nxt_y;
            }
            if (s[i] == 'R') d = (direct)((d + 1) % 4);
            if (s[i] == 'L') d = (direct)((d + 3) % 4);
            // cout << now(d) << '\n';
        }
        cout << x << " " << y << " " << now(d);
        if (isLost) cout << " LOST";
        cout << "\n";
        
    }
}