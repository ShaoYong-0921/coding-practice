#include <iostream>
#include <algorithm>

using namespace std;

long long ugly[1505];

int main(){
    ugly[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    for(int i=0; i<1500; ++i){
        long long nxt2 = ugly[p2] * 2;
        long long nxt3 = ugly[p3] * 3;
        long long nxt5 = ugly[p5] * 5;

        ugly[i + 1] = min({nxt2, nxt3, nxt5});
        if (ugly[i+ 1] == nxt2 ) ++ p2;
        if (ugly[i+ 1] == nxt3 ) ++ p3;
        if (ugly[i+ 1] == nxt5 ) ++ p5;
    }

    cout << "The 1500'th ugly number is " << ugly[1499] << ".\n";
}