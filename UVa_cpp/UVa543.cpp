#include <iostream>
#include <vector>

using namespace std;

bool prime[10000000];

void generatePrime(vector<int>& v){
    for(int i=0; i<10000000; i++)
        prime[i] = true;
    prime[0] = false; prime[1] = false;

    for(int i=2; i<10000000; i++)
        if (prime[i])
            for(int j=i+i; j<10000000; j+=i)
                prime[j] = false;
    for(int i=0; i<10000000; i++)
        if (prime[i]) v.push_back(i);
}

int main(){
    vector<int> p;
    generatePrime(p);
    // for( auto i : p )
    //     cout << i << " " ;
    // cout << '\n';
    int n;
    while(cin >> n && n != 0){
        int a = 0, b = 0;
        for(int i=0; i<n; i++){
            if (p[i] >= n){
                b = i - 1;
                break;
            }
        }
        // cout << "a: " << a << " b: " << b << '\n';
        while( a < b ){
            if (p[a] + p[b] == n) break;
            else if (p[a] + p[b] > n) -- b;
            else ++ a;
        }
        // cout << "p[" << a <<"] = " << p[a] << "; p[" << b << "] = " << p[b] <<'\n'; 
        if ( p[a] + p[b] != n ) cout << "Goldbach's conjecture is wrong.";
        else cout << n << " = " << p[a] << " + " << p[b] << '\n';
    }
}