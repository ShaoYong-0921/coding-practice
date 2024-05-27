#include <iostream>

using namespace std;

bool prime[1000];
int factor[1000];

void creatPrime(){
    int i, j;
    for(i=0; i<1000; i++)
        prime[i] = true; 
    prime[0] = prime[1] = false;
    for(i=2; i<1000; i++){
        if (prime[i])
            for(j=i*i; j<1000; j+=i)
                prime[j] = false;
    }
    // for(i=0; i<1000; i++)
    //     if (prime[i])
    //         cout << i << " ";
}



int main(){
    int s, t, i, j, index;
    creatPrime();
    while(cin >> s >> t && s != 0 && t != 0 ){
        index = 0;
        for(i=0; i<s; i++)
            if(prime[i])
                factor[index++] = i;
        for(i=0; i<index; i++)
            cout << factor[i] << " ";
    }
}