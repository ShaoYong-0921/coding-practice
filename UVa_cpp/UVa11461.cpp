#include <iostream>

using namespace std;

int main(){
    int a, b;
    while( cin >> a >> b && a != 0 && b!= 0){
        int cnt = 0;
        for(int i=1; i<=b; i++){
            if (a <= i*i && i*i <= b) ++ cnt;
            else if ( i*i > b) break;
        }
        cout << cnt << '\n'; 
    }
}