#include <iostream>
#include <vector>

using namespace std;

bool is_used(vector<int> v, int n ){
    for( auto i : v){
        if ( i == n ) return true;
    }
    return false;
}

int main(){
    int n;
    while( cin >> n && n != 0){

        cout << "Original number was " << n << '\n';

        vector<int> used;
        long long nxt = n, cnt = 0;
        while( is_used(used, nxt) == false){

            used.push_back(nxt);
            int num[10] = {0};

            while ( nxt != 0 ){
                int d = nxt % 10;
                nxt /= 10;
                ++ num[d];
            }
            long long des = 0, asc = 0;
            for (int i=0; i<10; ++ i){
                for (int j=0; j<num[i]; ++j){
                    asc = asc * 10 + i;
                }
            }
            for (int i=9; i>=0; -- i){
                for (int j=0; j<num[i]; ++j){
                    des = des * 10 + i;
                }
            }
            nxt = des - asc;
            cout <<  des << " - " <<  asc << " = " << nxt << '\n';
            ++ cnt;
        }
        cout << "Chain length " << cnt << endl << endl;
    }
}