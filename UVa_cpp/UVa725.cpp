#include <iostream>

using namespace std;

bool used[10] = {0};
bool sol;
int p[5];
int n;

void print(){
    int n = p[0]*10000 + p[1]*1000 + p[2]*100 + p[3]*10 + p[4];
    cout << n << endl;
}

bool check(){
    int abcde = p[0]*10000 + p[1]*1000 + p[2]*100 + p[3]*10 + p[4];
    if (abcde % n == 0){
        int fghij = abcde / n;
        int a = abcde;
        int b = fghij;

        bool digit[10] = {0};
        for(int i=0; i<5; ++i){
            digit[a % 10] = true;
            digit[b % 10] = true;
            a /= 10;
            b /= 10;
        }
        for(int i=0; i<10; ++i){
            if (!digit[i]) return false;
        }
        printf("%05d / %05d = %d\n", abcde, fghij, n);
        return true;
    }
    else return false;
}

void dfs(int depth){
    if (depth == 5){
        // print();
        if (check()) sol = true;
        return;
    }
    for(int i=0; i<10; ++i){
        if (!used[i]){
            used[i] = true;
            p[depth] = i;
            dfs(depth + 1);
            used[i] = false;
        }
    }
   
}

int main(){
    bool first = true;
    while(cin >> n && n != 0){
        if (!first) cout << '\n';
        first = false;
        sol = false;
        dfs(0);
        if (!sol) cout << "There are no solutions for " << n << ".\n";
    }
}