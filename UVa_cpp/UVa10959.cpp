#include <iostream>
#include <cstring>

using namespace std;

int queue[10000];
int DonGiovanni[1005];
bool part[1005][1005];

void bfs(int p){
    int curr, next;
    DonGiovanni[0] = 0;
    queue[0] = 0;
    int i, j, k;

    // cout << "DonGiovanni[0] = " << DonGiovanni[0] << "\n";
    // cout << "DonGiovanni[1] = " << DonGiovanni[1] << "\n";
    for(i=0, j=1; i<j; i++){
        curr = queue[i];
        for(k=0; k<p; k++){
            next = k;
            // cout << "curr = " << curr << " next = " << next << "\n";
            if (part[curr][next]){
                part[curr][next] = false;
                part[next][curr] = false;
                if (DonGiovanni[curr] < DonGiovanni[next])
                    DonGiovanni[next] = DonGiovanni[curr] + 1;
                else if (DonGiovanni[curr] > DonGiovanni[next])
                    DonGiovanni[curr] = DonGiovanni[next] + 1;
                // cout << "DonGiovanni["<< next << "] = " << DonGiovanni[next] << "\n";
                queue[j] = next;
                j ++;
            }
        }
    }
    // // cout << "DonGiovanni[0] = " << DonGiovanni[0] << "\n";
    // for(i=0; i<j; i++)
    //     cout << "queue[" << i << "] = " << queue[i] << "\n";
}

int main(){
    int t, p, d, n1, n2;
    bool first = true;
    cin >> t;
    for(int i=0; i<t; i++){
        memset(part, 0, sizeof(part));   
        for(int j=1; j<1005; j++)
            DonGiovanni[j] = 1e9+10;

        cin >> p >> d;
        // cout << "P = " << p << " D = " << d << "\n";
        for(int j=0; j<d; j++){
            cin >> n1 >> n2;
            // if (n1 > n2)
            //     swap(n1 , n2);
            part[n1][n2] = true;
            part[n2][n1] = true;
            // cout << "(" << n1 << "," << n2 << ")\n";
        }
        bfs(p);
        if (!first)
            cout << "\n";
        for(int i=1; i<p; i++)
            cout << DonGiovanni[i] << "\n";
        first = false;

    }
    return 0;
}