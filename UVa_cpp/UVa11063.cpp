#include <iostream>

using namespace std;

int b[105];
bool table[20005];

int main() {
    int n, i, j;
    int c = 0;
    while ( cin >> n ){
        int idx = 0;
        bool isB2 = true;

        for(i=0; i<20005; i++)
            table[i] = false;
        for(i=0; i<n; i++) 
            cin >> b[idx++];

        for(i=0; i<n; i++){
            for(j=i; j<n; j++){
                // cout << "b[" << i << "] = " << b[i] << "  ";
                // cout << "b[" << j << "] = " << b[j] << endl;
                if (b[i] <= 0){
                    isB2 = false;
                    break;
                }

                if (table[b[i] + b[j]]){
                    isB2 = false;
                    break;
                } 
                else
                    table[b[i] + b[j]] = true;
            }
        }

        for(i=0; i<n-1; i++)
            if (b[i] > b[i+1]) isB2 = false;

        if (isB2)
            cout << "Case #" << ++c << ": It is a B2-Sequence.\n\n";
        else
            cout << "Case #" << ++c << ": It is not a B2-Sequence.\n\n";
    }
}
