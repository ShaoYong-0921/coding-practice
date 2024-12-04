#include <iostream>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t --){
        int A[1005], B = 0, n;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> A[i]; 
        }
        for(int i=1; i<n; i++){
            // cout << "A["<< i << "] = " << A[i] << '\n';
            for(int j=0; j<i; j++){
                if (A[j] <= A[i]){
                    // cout << "A["<< j << "] = " << A[j] << '\n';   
                    B++;
                }
            }
        }
        cout << B << "\n";
    }
}