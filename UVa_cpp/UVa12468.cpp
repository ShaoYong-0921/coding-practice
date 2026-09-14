#include <iostream>

using namespace std;

int main(){
    int a, b;
    while (cin >> a >> b){
        if (a == -1 && b == -1) break;
        if (a > b) swap(a, b);
        int front, back;
        front = b - a;
        back  = 100 - b + a;
        if (front < back) cout << front;
        else cout << back;
        cout << '\n';
    }
}