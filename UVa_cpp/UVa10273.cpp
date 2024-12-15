#include <iostream>

using namespace std;

struct cow{
    int t;
    int m[15];
    bool live = true;
};

cow c[1005];
int used[255];

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        int loop = 1;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> c[i].t;
            c[i].live = true;
            loop = loop * c[i].t / gcd(loop, c[i].t);
            for(int j=0; j<c[i].t; j++){
                cin >> c[i].m[j];
            }
        }

        // cout << "loop = " << loop << '\n'; 
        int day = 0, mini, dead, milk, lastDay, cont = 0;
        while(loop --){
            if (cont == n) break;
            for(int i=0; i<255; i++) used[i] = 0;
            mini = ~ (1 << 31);
            dead = - 1;
            // cout << "mini = " << mini << endl; 
            for(int i=0; i<n; i++){
                if (c[i].live == false) continue;
                milk = c[i].m[ day % c[i].t ];
                used[milk] ++;
                // printf("NO. %d | %d days | %d milk\n", i, day, milk);
                if ( milk < mini){
                    dead = i;
                    mini = milk;
                    //printf("dead %d & mini = %d\n", dead, mini);
                }
            }
            if (used[mini] == 1) {
                c[dead].live = false;
                cont ++;
                lastDay = day + 1;
                loop = 1;
                for(int i=0; i<n; i++){
                    if (c[i].live == false) continue;
                    loop = loop * c[i].t / gcd(loop, c[i].t);
                }
                //cout << "loop = " << loop << '\n';
                // cout << "dead = " << dead << '\n';
            }
            day ++;
        }

        if (cont > 0)
            cout << n - cont << " " << lastDay << '\n';
        else 
            cout << n << " " << 0 << '\n'; 
    }
}