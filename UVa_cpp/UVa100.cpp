#include <iostream>

using namespace std;

void algorithm(int n, int& cont){
    // cout << n << " ";
    if ( n == 1 ) return;
    if (n % 2 == 1)
        n = n * 3 + 1;
    else
        n /= 2;
    algorithm(n, ++cont);
}

int main(){
    int i, j;
    while( cin >> i >> j){
        int maxium = 1, r, l;
        cout << i << " " << j << " ";
        if (j < i) swap(i, j);
        for (int num = i; num <=j ; num ++){
            int n = 1;
            algorithm(num, n);
            if (n > maxium) maxium = n;
            // cout << "num = " << num << " n = " << n << '\n';
        }
        cout << maxium << '\n';
    }
}

