#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    int n;
    cin >> n;
    while(cin >> n){
        int area = 1000 * 1000 * 6;
        for(a=1; a<=n; ++a){
            if (n % a) continue;

            for(b=1; b<=n; ++b){
                if (n % b) continue;

                for(c=1; c<=n; ++c){
                    // if (n % c) continue;
                    if (a * b * c != n ) continue;
                    int sum = 2 * ( a * b + b * c + a * c);
                    if (sum < area){
                        area = sum;
                        // cout << "new sum:" << area << endl;
                    } 
                }
            }
        }
        cout << area << endl;
    }
}