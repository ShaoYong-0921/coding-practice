#include <iostream>

using namespace std;

bool prime[1005];
bool used[1005];
int dist[1005];
int factor[1005];
int queue[1000000];

void creatPrimeTable(){
    int i, j;
    for(i=0; i<1005; i++)
        prime[i] = true; 
    prime[0] = prime[1] = false;
    for(i=2; i<1005; i++){
        if (prime[i])
            for(j=i*i; j<1005; j+=i)
                prime[j] = false;
    }
}

int primeNum(int x){
    int num = 0;
    for(int i=0; i<x; i++)
        if(prime[i] && x % i == 0)
            factor[num++] = i;
    // cout << x << " factor : ";
    // for(int i=0; i<num; i++)
    //     cout << factor[i] << " ";
    // cout << "\n"; 
    return num;
}


int bfs(int s, int t){
    int i, j, k, cur, nxt; 
    for(i=0; i<=1005; i++){
        used[i] = false;
        dist[i] = 0;
    }
    queue[0] = s;
    dist[s] = 0;
    for(i=0, j=1; i<j; i++){
        cur = queue[i];
        int n = primeNum(cur);
        if (cur == t) {
            return dist[cur];
        }
        for(k=0; k<n; k++){
            nxt = cur + factor[k];
            if (nxt > t) break;
            if (!used[nxt]){
                used[nxt] = true;
                dist[nxt] = dist[cur] + 1;
                queue[j] = nxt;
                j++;
            }
        }
    }
    return -1;
}

int main(){
    int s, t, i, j, count = 0;
    creatPrimeTable();
    while(cin >> s >> t && s != 0 && t != 0 ){
        int ans = bfs(s, t);
        cout << "Case " << ++count << ": " << ans << "\n";
    }
}