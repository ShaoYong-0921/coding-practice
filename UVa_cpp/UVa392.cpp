#include<iostream>
#include<sstream>

using namespace std;

int arr[10];

int main(){
    string s;
    while( getline(cin, s) ){
        stringstream ss(s);
        int n, i = 8;
        while( ss >> n){
            // cout << n << endl;
            arr[i--] = n;
        }
        bool first = true, change = false;
        for(int i=8; i>=0; i--){
            if (!arr[i]) continue;
            if (first) {
                first = false;
                if (arr[i] == -1 && i > 0) cout << "-";
                else if (arr[i] != 1 || i == 0 ) cout << arr[i];
            }
            else{
                if (arr[i] >= 0) cout << " + ";
                else cout << " - ";
                if (abs(arr[i]) != 1 || i == 0) cout << abs(arr[i]); 
            }
            if (i > 1) cout << "x^" << i;
            else if (i == 1) cout << "x";
            change = true;
        }
        if (!change) cout << 0;
        cout << '\n';

    }
}