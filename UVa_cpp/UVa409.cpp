#include <iostream>

using namespace std;

string a[30], excu[30];
int score[30];

int main(){
    int k, e;
    string s;
    int set = 0;
    while( cin >> k >> e){
        for(int i=0; i<k; ++i){
            cin >> a[i];
        }
        getline( cin, s );

        int maxcnt = 0;
        for(int i=0; i<e; ++i){
            getline( cin, excu[i] );
            s = excu[i];
            for(int j=0; j<s.size(); ++j){
                if ( 'A'<= s[j] && s[j] <= 'Z'){
                    s[j] += 'a' - 'A';
                }
                if (!isalpha(s[j])) s[j] = ' ';
            }
            // cout << s << '\n';
            int cnt = 0;
            for(int j=0; j<s.size(); ++j){
                string temp = "";
                while( j<s.size() && s[j]!= ' '){
                    temp += s[j];
                    ++ j;
                }

                // if (temp != "") cout << "temp = " << temp << endl;
                
                for(int l=0; l<k; ++l){
                    if (temp == a[l]) ++ cnt;
                }
            }
            // cout << "cnt = " << cnt << endl;
            if (cnt > maxcnt) maxcnt = cnt;
            score[i] = cnt;
        }

        cout << "Excuse Set #" << ++set << endl;
        for(int i=0; i<e; ++i){
            if (score[i] == maxcnt) cout << excu[i] << endl; 
        }
        cout << endl;

    }
}