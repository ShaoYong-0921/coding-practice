#include <iostream>

using namespace std;

int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        if (s1 == "0" && s2 == "0") break;

        int carry = 0, ans = 0;
        int size1 = s1.size(), size2 = s2.size();
        
        if (size1 > size2){
            for(int i=0; i < size1 - size2; i++)
                s2 = "0" + s2;
        }
        else if (size2 > size1){
            for(int i=0; i < size2 - size1; i++)
                s1 = "0" + s1;
        }
        // cout << "s1 = " << s1 << " s2 = " << s2 << '\n';
        for (int i=s1.size()-1; i>=0; i--){
            // cout << "i = " << i << '\n';
            int num1 = s1[i] - '0';
            int num2 = s2[i] - '0';
            if (num1 + num2 + carry >= 10){
                ans ++;
                carry = 1;
            }
            else carry = 0;
        } 
        if (ans == 0) cout << "No carry operation.\n";
        else if (ans == 1) cout << ans << " carry operation.\n";
        else cout << ans << " carry operations.\n";

        // cout << "ans = " << ans << '\n';
    }
}