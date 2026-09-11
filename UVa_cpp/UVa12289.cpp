#include <iostream>
#include <cstring>

using namespace std;

string str[3] = {"one", "two", "three"};

int main(){
    int t; cin >> t;
    while (t-- ){
        string s; cin >> s;
        // memset(err, sizeof(err), 0);
        int err[3] = {0};
        if (s.size() == 3){
            for(int i=0; i<3; i++){
                if (s[i] != str[0][i]) err[0] ++;
                if (s[i] != str[1][i]) err[1] ++;
            }
            for(int i=0; i<2; i++){
                //cout << "i: " << err[i] << endl;
                if (err[i] == 1 || err[i] == 0) cout << i + 1<< '\n';
            }
        }
        else{
            for(int i=0; i<5; i++)
                if (s[i] != str[2][i]) err[2] ++;
            if (err[2] == 1 || err[2] == 0) cout << "3" << '\n';
        }
    }

}