#include <iostream>
#include <iomanip>

using namespace std;

void bangla(unsigned long long n){
    // cout << " n = " << n << '\n';
    if (n >= 10000000){
        bangla( n / 10000000);
        n %= 10000000;
        cout << " kuti";
    }
    if (n >= 100000){
        cout << " " << n / 100000 << " lakh";
        return bangla( n % 100000);
    }
    else if (n >= 1000){
        cout << " " << n / 1000 << " hajar";
        return bangla( n % 1000);
    }
    else if (n >= 100){
        cout << " " << n / 100 << " shata";
        return bangla( n % 100);
    }
    else{
        if (n != 0)
            cout << " " << n;
    } 
}


int main(){
    unsigned long long n;
    int count = 0;
    while(cin >> n){
        cout << setw(4) <<++count << ".";
        if ( n == 0 ){
            cout << " 0\n";
            continue;
        } 
        bangla(n);
        cout << '\n';
    }

}