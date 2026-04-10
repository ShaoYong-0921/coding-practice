#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int c, m, n;
    cin >> c;
    while(c --){
        cin >> n >> m;
        map<int, int> mp;
        queue<int> q;
        int maxium = 0;
        for(int i=0; i<n; ++i){
            cin >> mp[i];
            maxium = max(mp[i], maxium);
            q.push(i);
        }

        bool fin = false;
        int time = 0;
        while(!fin){
            int front = q.front();
            if (mp[front] == maxium){
                if(front == m) fin = true;
                ++ time;
                mp[front] = -1;
                maxium = 0;
                for(auto &i : mp) maxium = max(i.second, maxium);
            }
            else{
                q.push(front);
            }
            q.pop();
        }
        cout << time << '\n';

    }
}