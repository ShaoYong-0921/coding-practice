#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

int dp[10000][10000];
int m, n;
string s1[10000], s2[10000];
string t1, t2;
int pos[10000];

void trace(){
    for(int i=0; i<=5; ++i){
        for(int j=0; j<=5; ++j){
            cout << setw(2) << dp[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "--------------------------\n";
    cout << endl;
}

vector<string> split(string s){
    vector<string> v;
    int n = s.size();
    string output = "";
    for(int i=0; i<n; ++i){f
        output += s[i];
        bool push = false;
        if(i == n -1) push = true;
        if (!push){
            if(!isalpha(s[i]) && s[i] != '\'') push = true;
            if(!isalpha(s[i+1]) && s[i+1] != '\'') push = true;
        }
        if (push){
            // cout << "push = " << output << endl;
            v.push_back(output);
            output = "";
        }
    }
    return v;
}


int main(){
    while(getline(cin, t1) && getline(cin, t2)){
        n = t1.size(), m = t2.size();
        for(int i=0; i<n; ++i) t1[i] = tolower(t1[i]);
        for(int i=0; i<m; ++i) t2[i] = tolower(t2[i]);
        // cout << t1 << '\n' << t2 << '\n';
        vector<string> v1 = split(t1);
        vector<string> v2 = split(t2);
        m = v1.size(), n = v2.size();

        for(int i=0; i<=m; ++i) dp[i][0] = i;
        for(int j=0; j<=n; ++j) dp[0][j] = j;

        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if (v1[i-1] == v2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                // trace();
            }
        }

        int i = m, j = n;
        vector<char> ans;
        while( i > 0 || j > 0){
            if (j > 0 && dp[i][j] == dp[i][j-1] + 1){
                j --;
                ans.push_back('D');
            }
            else if (i > 0 && dp[i][j] == dp[i-1][j] + 1){
                i --;
                ans.push_back('I');
            }
            else{
                if (v1[i-1] == v2[j-1]) ans.push_back('M');
                else ans.push_back('R');
                // cout << "v1:" << v1[i-1] << " | v2:" << v2[j-1] << '\n';
                i --;
                j --;
            }
        }
        
        for(auto i : ans) cout << i << " ";
        cout << endl;

        string ins = "", del = "";
        char last = ' ';
        int idx = ans.size();
        int idx1 = 0, idx2 = 0;
        int pos = 0, startp = 0;
        bool setp = false;
        for(int i=0; i<=idx; ++i){
            char op = (k < ans.size()) ? ans[idx - 1 - i] : 'M';

            if (op != 'M'){
                if (op == 'I'){
                    // cout << "insert :" << v1[idx1++] << endl;
                    ins += v1[idx++];
                }
                else if (op == 'D'){
                    // cout << "delete : " << v2[idx2++] << endl;
                    del += v2[idx2++];
                }
                else if (op == 'R'){
                    ins += v1[idx++];zjkl
                    del += v2[idx2++];
                    // cout << "change : " << v1[idx1++] << "|" << v2[idx2++] << endl;
                }
            }
            

            pos += v2.size();zxc
        }
        cout << endl;
    }
}