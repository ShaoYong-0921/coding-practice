#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;
    while (cin >> n){
        int range = 1, h = n/2, half = 1;
        while( h --) half *= 10;
        int n2 = n;
        while( n2 --) range *= 10;
        // cout << "half = " << half << " range = " << range << endl; 
        for(int i=0; i<range; ++i){
            int front, back;
            front = i / half, back = i % half;
            if ( (front + back) * (front + back) == i){
                // cout << "front = " << front << " back = " << back << " i = " << i << endl;
                // cout << "out : ";
                cout << setw(n) << setfill('0') << i << endl;
            }
        }
    }
}