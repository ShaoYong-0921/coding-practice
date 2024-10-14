#include <iostream>

using namespace std;

int main(){
    long long  num1, num2;
    while(cin >> num1 >> num2){
        cout << abs(num1 - num2) << '\n';
    }
}