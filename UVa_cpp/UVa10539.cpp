#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MAX = 10e12;
bool prime[10000000];
vector<long long> almostprime;

void generate(){
    for(long long i=0; i<1000000; i++){
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;

    for(long long i=2; i<1000000; i++){
        if (prime[i])
            for (long long j=i+i; j<1000000; j+=i){
                prime[j] = false;
            }
    }
}

void almostPrime(){
    generate();
    for(long long i=0; i<10000000; i++){
        if (prime[i]){
            for(long long j=i*i; j<MAX; j*=i){
                almostprime.push_back(j);
            }
        }
    }
    sort(almostprime.begin(), almostprime.end());
}

int main(){
    almostPrime();
    int n;
    cin >> n;
    while(n --){
        long long l ,h;
        long long ans = 0;
        cin >> l >> h;
        int count = upper_bound(almostprime.begin(), almostprime.end(), h) -
                    lower_bound(almostprime.begin(), almostprime.end(), l);
        cout << count << '\n';
    }
    return 0;
}