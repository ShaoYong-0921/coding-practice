#include <iostream>

using namespace std;

long long gcd(unsigned long long a, unsigned long long b){
    while(b > 0){
        unsigned long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    unsigned long long v1, d1, v2, d2;
    unsigned long long count = 0;
    while( cin >> v1 >> d1 >> v2 >> d2){
        if ( v1 == 0 && v2 == 0 && d1 == 0 && d2 == 0) break;
        cout << "Case #" << ++count << ": ";
        if ( d1 * v2 < d2 * v1) cout << "You owe me a beer!\n";
        else cout << "No beer for the captain.\n";

        unsigned long long numer = d1 * v2 + d2 * v1;
        unsigned long long deno = v1 * v2  * 2;
        unsigned long long g = gcd(numer, deno);
        numer /= g;
        deno /= g;
        
        cout << "Avg. arrival time: ";
        if ( deno == 1 ) cout << numer << '\n';
        else 
            cout << numer << "/" << deno  << '\n';
    }

}