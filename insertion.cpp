#include <iostream>

using namespace std;

//input data
int a[10] = {19, 29, 2, 27, 3, 23, 5, 9, 8, 0};

int main(){
    //print orginal array
    for (auto i : a) cout << i << ' ';
    cout << '\n';

    //insertion sort
    int n = sizeof(a) / sizeof(a[0]);
    for(int j=1; j<n; j++){
        int i, x = a[j];
        for(i=j-1; a[i] > x && i>=0; i--){
            a[i+1] = a[i];
        }
        a[i+1] = x;
    }

    // print sorted array
    for (auto i : a) cout << i << ' ';
    cout << '\n';
}