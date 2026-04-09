#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a1[30], a2[30];

int main(){
    string s1, s2;
    while(getline(cin, s1)){
        getline(cin, s2);
        // vector<int> v1, v2;
        memset(a1, 0, sizeof(a1));
        memset(a2, 0, sizeof(a2));

        for(int i=0; i<s1.size(); ++i) a1[s1[i] - 'A']++;
        for(int i=0; i<s2.size(); ++i) a2[s2[i] - 'A']++;

        // for(int i=0; i<30; ++i){
        //     cout << (char)('A' + i) << ":" <<  a1[i] << endl;
        // }

        sort(a1, a1+30);
        sort(a2, a2+30);

        bool same = true;
        for(int i=0; i<30; ++i){
            // cout << a1[i] << " | " << a2[i] << endl;
            if (a1[i] != a2[i]) same = false;
        }
        if (same) cout << "YES\n";
        else cout << "NO\n";
    }
}