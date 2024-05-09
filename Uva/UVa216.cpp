#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double x[10], y[10], ans, ans_d[10];
int path[10], ans_p[10];
bool used[10];
int n;

double distance(double x, double y){
    return sqrt(x * x + y * y);
}

void dfs(int depth){
    if (depth == n){
        double total = 0, dist[10];
        for(int i=0; i<n-1; i++){
            // cout << path[i] << " ";
            // cout << "connect (" << x[path[i]] << ", " << y[path[i]] << ") "
            //     << "to (" << x[path[i+1]] << ", " << y[path[i+1]] << ")\n";
            dist[i] = distance(x[path[i]]- x[path[i+1]], y[path[i]] - y[path[i+1]]) + 16;
            total += dist[i];
            // cout << "dist = " << dist << "\n";
        }
        // cout << "\n";
        if (ans > total){
            ans = total;
            for(int i=0; i<n; i++){
                ans_p[i] = path[i];
                ans_d[i] = dist[i];
            }

        }
        // cout << "ans = " << ans << "\n";
        return;

    }
    for(int i=0; i<n; i++){
        if (!used[i]){
            used[i] = true;
            path[depth] = i;
            // cout << "path = " << path[depth] << "\n"; 
            dfs(depth + 1);
            used[i] = false;
        }   
    }
}

int main(){
    int count = 0;
    while(cin >> n && n != 0){
        cout << "**********************************************************\n";
        cout << "Network #" << ++count << "\n";
        ans = 2147483647;
        for(int i=0; i<n; i++){
            cin >> x[i] >> y[i];
            used[i] = false;
        }
        dfs(0);

        cout << fixed;        
        for(int i=0; i<n-1; i++){
            cout << "Cable requirement to connect ";
            cout << setprecision(0) << "(" << x[ans_p[i]] << "," << y[ans_p[i]] << ") to ";
            cout << setprecision(0) << "(" << x[ans_p[i+1]] << "," << y[ans_p[i+1]] << ") is ";
            cout << setprecision(2) << ans_d[i] << " feet.\n";
        }
        cout << "Number of feet of cable required is ";
        cout << setprecision(2) << ans << ".\n";
            

    }
}