#include <iostream>

using namespace std;

enum status {fillA, fillB, emptyA, emptyB, pourAB, pourBA};

struct node{
    int a, b, last;
    status s;
};

bool used[1005][1005];
node queue[1000000];

string addString(node n){
    // cout << "Node(" << n.a << "," << n.b << ") ";
    switch(n.s){
        case fillA: return "fill A\n";
        case fillB: return "fill B\n"; 
        case emptyA: return "empty A\n"; 
        case emptyB: return  "empty B\n"; 
        case pourAB: return "pour A B\n"; 
        case pourBA: return "pour B A\n"; 
        default:
            return "none\n";
    }
}

string bfs(int a, int b, int n){
    node cur, nxt;
    int i, j, k;
    for(i=0; i<1005; i++)
        for(j=0; j<1005; j++)
            used[i][j] = false;
    used[0][0] = true;
    queue[0].a = queue[0].b = 0;
    queue[0].last = -1;
    for(i=0, j=1; i<j; i++){
        cur = queue[i];
        if(cur.a == n || cur.b == n){
            string ans = addString(cur), s;
            int l = cur.last;
            node n;
            while(l != 0){
                n = queue[l];
                s = addString(n);
                ans = s + ans;
                l = n.last;
            }
            // cout << "cur a = " << cur.a << " b = " << cur.b << "\n";
            // cout << "last a = " << queue[l].a << " b = " << queue[l].b << "\n"; 
            return ans;
        }
        for(k=0; k<6; k++){
            nxt = cur;
            nxt.s = (enum status)(k);
            if (nxt.s == fillA) nxt.a = a;
            else if (nxt.s == fillB) nxt.b = b;
            else if (nxt.s == emptyA) nxt.a = 0;
            else if (nxt.s == emptyB) nxt.b = 0;
            else if (nxt.s == pourAB){
                if (cur.a + cur.b > b){
                    nxt.b = b;
                    nxt.a = cur.a + cur.b - b;
                }else{
                    nxt.a = 0;
                    nxt.b = cur.a + cur.b;
                }
            }else if (nxt.s == pourBA){
                if (cur.a + cur.b > a){
                    nxt.a = a;
                    nxt.b = cur.a + cur.b - a;
                }else{
                    nxt.a = cur.a + cur.b;
                    nxt.b = 0;
                }
            }
            if (used[nxt.a][nxt.b]) continue;
            else{
                used[nxt.a][nxt.b] = true;
                nxt.last = i;
                queue[j] = nxt;
                j++;
            }
        }
    }
    return "fail";
}

int main(){
    int ca, cb, n;
    while(cin >> ca >> cb >> n){
        string ans;
        ans = bfs(ca, cb, n);
        cout << ans << "success\n";
    }
}