#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main(){
    string s1, s2;
    while(getline(cin, s1) && getline(cin, s2)){
        stringstream ss1(s1), ss2(s2);
        set<int> a, b;
        int n;
        while( ss1 >> n ) a.insert(n);
        while( ss2 >> n ) b.insert(n);
        bool diff = true;
        int common = 0;
        for(auto &i : a){
            if (b.count(i)) { diff = false; common ++; }
        }

        if (common == a.size() && common == b.size())cout << "A equals B\n";        
        else if (common == b.size()) cout << "B is a proper subset of A\n";
        else if (common == a.size()) cout << "A is a proper subset of B\n";
        else if (diff) cout << "A and B are disjoint\n";
        else cout << "I'm confused!\n";
    }
}
