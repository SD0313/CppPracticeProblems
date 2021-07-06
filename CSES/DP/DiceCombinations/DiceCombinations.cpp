//CSES: https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    int dp[n+1] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            dp[i] += (i-j >= 0) ? dp[i-j] : 0;
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
