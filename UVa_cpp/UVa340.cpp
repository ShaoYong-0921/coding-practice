#include <iostream>

using namespace std;

int secret[1000], guess[1000], count[10], rebuild[10];

int main(){
    int n, i, j, k, game = 0;
    while(true){
        cin >> n;
        if (n == 0) break;
        //init array
        for(i=0; i<10; i++)
            count[i] = 0;
        //cin secret
        for(i=0; i<n; i++){
            cin >> secret[i];
            count[secret[i]] ++;
        }
        cout << "Game " << ++ game << ":\n";
        while(true){
            bool flag = true;
            int strong = 0, weak = 0;
            //init rebuild
            for(i=0; i<10; i++)
                rebuild[i] = 0;
            // cin guess
            for(i=0; i<n; i++){
                cin >> guess[i];
                if (guess[i] != 0)
                    flag = false;
            }
            if (flag) break;
            
            /* cout 
            cout << "secret = ";
            for(i=0; i<n; i++)
                cout << secret[i] << " ";
            cout << "\nguess  = ";
            for(i=0; i<n; i++)
                cout << guess[i] << " ";
            cout << "\n";
            for(i=0; i<10; i++){
                cout << "[" << i << "] = " << count[i] << "\n";
            }
            */

            for(i=0; i<n; i++){
                if (guess[i] == secret[i]){
                    strong++;
                    count[guess[i]] --;
                    rebuild[guess[i]] ++;
                }
            }

            for(i=0; i<n; i++){
                if (count[guess[i]] != 0){
                    if (guess[i] == secret[i]){
                        continue;
                    }
                    else{
                        weak ++;
                        count[guess[i]] --;
                        rebuild[guess[i]] ++;
                    }
                }
            }
            // cout << "strong = " << strong << "\n";
            // cout << "weak   = " << weak << "\n";

            // for(i=0; i<10; i++){
            //     cout << "r[" << i << "] = " << rebuild[i] << "\n";
            // }
            
            for(i=0; i<10; i++){
                count[i] += rebuild[i];
                // cout << "f[" << i << "] = " << count[i] << "\n";
            }
            
            cout << "    (" << strong << "," << weak << ")\n";
        }
    }
}