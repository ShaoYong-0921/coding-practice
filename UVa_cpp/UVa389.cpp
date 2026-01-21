#include <iostream>
#include <iomanip>

using namespace std;

char b[16] = {'0', '1', '2', '3', '4','5', '6', '7', '8', '9', 
'A', 'B', 'C', 'D', 'E', 'F'};

int main(){
    string s;
    int base1, base2;
    while( cin >> s >> base1 >> base2 ){
        int num = 0, w = 1;
        for(int i=s.size()-1; i>=0; -- i){
            if ('A' <= s[i] && s[i] <= 'F') num += (int)(s[i] - 'A' + 10) * w;
            else num += (int)(s[i] - '0') * w;
            // printf("s[%d] = %c | num = %d | w = %d\n", i, s[i], num, w);
            w *= base1;
        }
        // cout << num << endl;
        string ans = "";
        while(num > 0){
            char c = b[num % base2];
            ans = c + ans;
            num /= base2;
        }
        if (ans == "") ans = "0"; 
        cout << setw(7) << right;
        if (ans.size() > 7) cout << "ERROR";
        else cout << ans;
        cout << endl;
    }
}