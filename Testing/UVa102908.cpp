#include <iostream>

using namespace std;

int main(){
    long long n;
    while( cin >> n && n != 0) {
        long long s = 0, i = 1;
        while( s < n ){
            s += i;
            // printf("S=%d, n=%d, i=%d\n", s, n, i);
            i ++;
        }
        if ( s == n ) 
            cout << i << " " << i << '\n'; 
        else
            cout << s - n << " " << i - 1 << '\n';
    }
}