#include <iostream>

using namespace std;

int n[205];

int main(){
    for (int i=0; i<205; ++i){
        n[i] = i * i * i;
    }
    for (int l=2; l<=200; ++l){
        for (int i=2; i<205; ++i){
            for (int j=i+1; j<205; ++j){
                for(int k=j+1; k<205; ++k){
                    if (n[l] == n[i] + n[j] + n[k]){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", l, i, j , k);
                    }
                }
            }
        }
    }
}