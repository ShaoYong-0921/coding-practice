#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for(int j=y1; j<y2; j++){
            ans += j + 1;
        }
        cout << "1/ans = " << ans << '\n';
        ans = ans - x1 + x2;
        cout << "2/ans = " << ans << '\n';
    }
}