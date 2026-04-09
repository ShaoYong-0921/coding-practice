#include <iostream>

using namespace std;

int main() {
 
    int n;
    while (cin >> n && n != 0) {
        if (n < 4 || n % 2 != 0) {
            cout << "Impossible\n";
            continue;
        }

        int edges = n + (n / 2);
        cout << edges << "\n";

        for (int i = 1; i < n; ++i) {
            cout << i << " " << i + 1 << "\n";
        }

        cout << 1 << " " << n << "\n"; 

        int half = n / 2;
        for (int i = 1; i <= half; ++i) {
            cout << i << " " << i + half << "\n";
        }
    }
    return 0;
}