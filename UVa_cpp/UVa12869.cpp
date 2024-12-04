#include <iostream>

using namespace std;

int main(){
    long long low, high;
    while( cin >> low >> high){
        if (low == 0 && high == 0 ) break;


        long long l = low / 5;
        long long h = high /5;

        cout << h - l + 1 << '\n';
    }
}