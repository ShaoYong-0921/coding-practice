#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int a[1005];

int main(){
    int n;
    while(cin >> n && n){
        string s;
        getline(cin, s);

        while(getline(cin, s) && s != "0"){
            stringstream ss(s);
            for(int i=0; i<n; ++i) ss >> a[i];
            // for(int i=0; i<n; ++i) cout << a[i] << " ";
            // cout << '\n';
            stack<int> sta;
            int idx = 0;
            for(int i=1 ;i<=n; ++i){
                bool add = true;
                if (a[idx] == i){
                    idx ++;
                    add = false;
                    // continue;
                } 
                while( !sta.empty() && sta.top() == a[idx]){
                    sta.pop();
                    idx ++;
                }
                    
                if (add) sta.push(i);
            }
            // cout << "idx = " << idx << " " << n << endl;
            if (idx == n) cout << "Yes\n";
            else cout << "No\n";

        }
        cout << '\n';
    }
}