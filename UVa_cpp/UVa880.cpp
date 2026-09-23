#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n; 
    while(cin >> n){
        // int layer;
        // for(layer = 1 ; layer * (layer + 1 )/ 2 < n; ++layer);
        // cout << "layer = " << layer << " cnt = " << (layer * (layer + 1 )/ 2) << endl;
        long long layer = ceil((sqrt(8.0 * n + 1) - 1) / 2);

        int x = (layer * (layer + 1 )/ 2) - n + 1;
        int y = layer + 1 - x;
        cout << x << "/" << y << endl; 
    }


}