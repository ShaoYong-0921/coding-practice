#include <bits/stdc++.h>

using namespace std;

int used[1005] = {0};

int main(){
    int a, b;
    bool first = true;
    while(cin >> a >> b && !(a == 0 && b == 0)){
        memset(used, -1, sizeof(used));
        int digit = 0; 
        string ans = ".";
        while(used[a] == -1 && a != 0){
            used[a] = digit ++;
            a *= 10;
            ans += char('0' + a/b);
            if (ans.size() >= 50){
                string temp = "";
                for(int i=0; i<ans.size(); ++i){
                    if (i < 50) cout << ans[i];
                    else temp += ans[i];
                }
                cout << '\n';
                ans = temp;
            }
            a = a % b;
            //cout << "a = " << a << endl;
        }
        if (ans != "") cout << ans << '\n';
        if (a == 0) cout << "This expansion terminates.\n";
        else cout << "The last " <<  digit - used[a] << " digits repeat forever.\n";\
        cout << '\n';
        //cout << a << endl;
    }
}