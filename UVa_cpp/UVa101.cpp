#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm> 

using namespace std;

void cleartop(vector<vector<int>> & arr, int a);
void print(vector<vector<int>> vec);
void pileon(vector<vector<int>> & arr, int a, int b);

map<int, int> mp;

int main(){
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    // cout << n << '\n';
    vector< vector<int> > v(n);
    for(int i=0; i<n; ++i){
        v[i].push_back(i);
        mp[i] = i;
    }
    while(getline(cin, s) && s != "quit"){
        stringstream ss(s);
        string op1, op2;
        int a, b;
        ss >> op1 >> a >> op2 >> b;
        // cout << op1 << " " <x< n1 << " " << op2 << " " << n2 << '\n';
        if (mp[a] == mp[b]) continue;
        // print(v);
        if (op1 == "move" && op2 == "onto"){
            cleartop(v, a);
            cleartop(v, b);
            v[mp[a]].pop_back();
            v[mp[b]].push_back(a);
            mp[a] = mp[b];
        }
        if (op1 == "move" && op2 == "over"){
            cleartop(v, a);
            v[mp[a]].pop_back();
            v[mp[b]].push_back(a);
            mp[a] = mp[b];
        }
        if (op1 == "pile" && op2 == "onto"){
            cleartop(v, b);
            pileon(v, a, b);
        }
        if (op1 == "pile" && op2 == "over"){
            pileon(v, a, b);
        }
        // print(v);
        // cout << "----------------\n";

    }
    print(v);
}

void cleartop(vector<vector<int>> & arr, int a){
    while(arr[mp[a]].back() != a){
        int k = arr[mp[a]].back();
        arr[mp[a]].pop_back();
        arr[mp[k]].push_back(k);
        mp[k] = k;
    }
}


void pileon(vector<vector<int>> &arr, int a, int b) {
    int posA = mp[a];
    int posB = mp[b];

    auto it = find(arr[posA].begin(), arr[posA].end(), a);

    for (auto i = it; i != arr[posA].end(); ++i) {
        mp[*i] = posB;
    }

    arr[posB].insert(arr[posB].end(), it, arr[posA].end());

    arr[posA].erase(it, arr[posA].end());
}


void print(vector<vector<int>> vec){
    int j = 0;
    for(auto &i : vec){
        cout << j << ":";
        j ++;
        for(int j=0; j<i.size(); ++j){
            cout << " " << i[j];
        }
        cout << '\n';
    }
}