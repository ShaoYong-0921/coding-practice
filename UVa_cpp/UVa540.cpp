#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

void print(vector<queue<int>> q){
    for(auto i : q){
        queue<int> tmp = i;
        while(!tmp.empty()) {
            cout << tmp.front() << " | ";
            tmp.pop();
        }
    }
    cout << endl;
}


int main(){
    int t, cnt = 0;
    string s;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> t && t!=0){

        cout << "Scenario #" << ++ cnt << '\n';
        int n;
        
        map<int, int> mp;
        for(int j=0; j<t; ++j){
            cin >> n;
            for(int i=0; i<n; ++i){
                int num;
                cin >> num;
                mp[num] = j;
                // cout << "num: " << num << " | " << mp[num] << endl; 
            }
        }
        string s, op, ans = "";
        int x;
        vector<queue<int>> q;
        getline(cin, s);
        while(getline(cin, s)){
            stringstream ss(s);
            ss >> op >> x;
            // cout << op << " ";
            if (op == "STOP") break;
            else if (op == "ENQUEUE"){
                        
                bool find = false;
                for(auto &i : q){
                    if (mp[i.front()] == mp[x]){
                        i.push(x);
                        find = true;
                    } 
                }
                if (!find){
                    queue<int> que;
                    que.push(x);
                    q.push_back(que);
                }
                // print(q);
            }
            else{
                if (!q.empty()) {
                        cout << q[0].front() << '\n';
                        q[0].pop();

                        if (q[0].empty()) {
                            q.erase(q.begin()); // 刪除 vector 的第一個元素
                        }
                    }

            }
        }
        cout << '\n';

    }
}