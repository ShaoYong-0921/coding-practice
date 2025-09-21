#include <iostream>

using namespace std;

int arr[1005];

int main(){
    int n;
    while( cin >> n ){
        for(int i=0; i<n; i++ ) cin >> arr[i];
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1-i; j++){
                if (arr[j] > arr[j+1]){
                    ++ cnt;
                    swap(arr[j], arr[j+1]);
                }
                // for(int i=0; i<n; i++) cout << arr[i] << " ";
                // cout << '\n';
            }

        }
        cout << "Minimum exchange operations : " << cnt << '\n';
    }
}