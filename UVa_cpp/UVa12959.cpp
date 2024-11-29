#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long J, R, i, j;
    while( cin >> J >> R){
        vector<long long> v(J);
        // if (J == 0 && R == 0) break;
        int count = 0;
        for(i=0; i<R; i++){
            for(j=0; j<J; j++){
                long long num;
                cin >> num;
                v[j%J] += num;
                // cout << "j = " << j << " J = " << J <<endl;
                // cout << "v[" << j%J << "] = " << v[j%J] << endl; 
            }
        }
        long long max = 0;
        long long winner;
        for(i=0; i<J; i++){
            // cout << "v[" << i << "] = " << v[i] << endl; 
            if (v[i] >= max){
                winner = i;
                max = v[i];
            }
        }
        cout << winner + 1 << '\n'; 
    }

}
