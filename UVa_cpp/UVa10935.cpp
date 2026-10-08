#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        deque<int> d;
        vector<int> v;
        for(int i=1; i<=n; ++i) d.push_back(i);
        while(d.size() != 1){
            int front = d.front();
            v.push_back(front);
            d.pop_front();
            front = d.front();
            d.pop_front();
            d.push_back(front);
        }
        cout << "Discarded cards:";
        for(int i=0; i<v.size(); ++i) {
            if (i > 0) cout << ",";
            cout << " " << v[i];
        }
        cout << "\nRemaining card: " << d.front() << '\n';
    }
}