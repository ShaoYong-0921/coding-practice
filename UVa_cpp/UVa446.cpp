#include <iostream>
#include <sstream>

using namespace std;

string str[16] = { "0000", "0001", "0010", "0011", 
                   "0100", "0101", "0110", "0111",
                   "1000", "1001", "1010", "1011",
                   "1100", "1101", "1110", "1111"};

int main(){
    int n; cin >> n;
    string k; getline(cin, k);
    while(n --){
        auto todec = [&](string s) -> int {
            int n = 0, sum = 0;
            for(auto i : s){
                if ( 'A' <= i && i <= 'F') n = (i - 'A') + 10;
                else n = i - '0';
                sum = sum * 16 + n;
            }
            return sum;
        };
        auto print = [&](string s) -> void {
            cout << "0";
            for(int i=0; i< 3-s.size(); ++i) cout << str[0];
            //cout << s << endl;
            for(int i=0; i<s.size(); i++){
                if ( 'A' <=  s[i] && s[i] <= 'Z') cout << str[10 + s[i] - 'A'];
                else cout << str[s[i] - '0'];
            }
        };

        string input; 
        getline(cin, input);
        stringstream ss(input);
        string a, b, c;
        while(ss >> a >> b >> c){
            // cout << a << " " << b << " " << c << endl;
            print(a);
            cout << " " << b << " ";
            print(c);
            int ans = (b == "+" ) ? todec(a) + todec(c) : todec(a) - todec(c);
            cout << " = " << ans << '\n';
        } 

    }
}