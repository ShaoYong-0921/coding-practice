#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX = 30001;
const int coins[] = {1, 5, 10, 25, 50};

int main() {
    vector<long long> dp(MAX, 0);
    dp[0] = 1;  // 凑成0分的方法只有1種：不使用任何硬幣

    // 動態規劃：對每個硬幣面額更新所有大於等於它的金額
    for (int c : coins) {
        for (int i = c; i < MAX; ++i) {
            dp[i] += dp[i - c];
        }
    }

    int n;
    while (cin >> n) {
        if (dp[n] == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
    }

    return 0;
}
