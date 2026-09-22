#include <iostream>
#include <sstream>

using namespace std;

int main(){
    int t; cin >> t;
    cin.ignore();
    while(t --){
        string s; getline(cin, s);
        stringstream ss(s);
        int n, sum = 0;
        while (ss >> n){
            int m = ( n / 1000 * 2);
            int k = ( n % 100 / 10 * 2);
            // cout << "m = " << m << "| k = " << k << endl;
            sum += m / 10 + m % 10 + k / 10 + k % 10;
            sum += (n % 1000 / 100) + n % 10;
        } 
        //cout << "sum = " << sum << endl;
        if (sum % 10) cout << "Invalid\n";
        else cout << "Valid\n";
    }
}