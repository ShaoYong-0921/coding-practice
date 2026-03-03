#include <iostream>

using namespace std;

int a[10000], b[10000];

int main(){
    string s1, s2;
    while(getline(cin, s1)){
        getline(cin ,s2);
        s1 += ' ', s2 += ' ';
        // cout << INT_MAX << endl;
        int n1 = 0, n2 = 0, idx1 = 0, idx2 = 0;
        for(int i=0; i<s1.size(); ++i){
            if (s1[i] == ' '){
                bool is_in = false;
                for(int j=0; j<idx1; ++j){
                    if (n1 == a[j]){
                        is_in = true;
                        break;
                    }
                }
                if (!is_in) a[idx1 ++] = n1;   
                n1 = 0;
                continue;
            }
            n1 = n1 * 10 + (s1[i] - '0');
        }
        for(int i=0; i<s2.size(); ++i){
            if (s2[i] == ' '){
                bool is_in = false;
                for(int j=0; j<idx2; ++j){
                    if (n2 == b[j]){
                        // cout << "n2 = " << n2 << endl;
                        is_in = true;
                        break;
                    }
                }
                if (!is_in) {
                    // cout << "in " << n2 << endl;
                    b[idx2 ++] = n2;
                }
                n2 = 0;
                continue;
            }
            n2 = n2 * 10 + (s2[i] - '0');
        }
        // cout << "idx1 = " << idx1 << " idx2 = " << idx2 << endl;

        bool change = false;
        if (idx1 < idx2){
            swap(a, b);
            swap(idx1, idx2);
            change = true;
        }

        int cnt = 0, cnt1 = 0;
        for(int i=0; i<idx2; ++i){
            // cout << "b[" << i << "] = " << b[i] << endl;
            bool in = false;
            for(int j=0; j<idx1; ++j){
                if(b[i] == a[j]){
                    in = true;
                    // cout << "a[" << j << "] = " << a[j] << endl;
                    break;
                }
            }
            if(in) ++ cnt;
            else ++ cnt1;

        }
        if(cnt == idx2 && idx1 == idx2) cout << "A equals B\n";
        else if(cnt == idx2 && !change) cout << "B is a proper subset of A\n";
        else if (cnt == idx2 && change) cout << "A is a proper subset of B\n";
        else if (cnt1 == idx2) cout << "A and B are disjoint\n";
        else cout << "I'm confused!\n";

    }
}