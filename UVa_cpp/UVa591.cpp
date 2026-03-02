#include <iostream>

using namespace std;

int a[55];

int main(){
    bool first = true;
    int n, cnt = 0;
    while(cin >> n && n != 0){
        int sum = 0, avg; 
        for(int i=0; i<n; ++i){
            cin >> a[i];
            sum += a[i];
        }
        avg = sum / n;
        int move = 0;
        for(int i=0; i<n; ++i){
            move += abs(a[i] - avg);
        }
        cout << "Set #" << ++cnt << endl;
        cout << "The minimum number of moves is " << move / 2 << ".\n" << endl;
    }

}