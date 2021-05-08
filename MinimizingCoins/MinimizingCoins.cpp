//CSES: https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main() {
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0 ;i < n; i++) {
        int coin;
        cin >> coin;
        coins[i] = coin;
    }
    int dp[x+1];
    fill(dp, dp+x+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i-coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    if (dp[x] == INF) {
        cout << -1 << '\n';
        return 0;
    }
    cout << dp[x] << '\n';
    return 0;
}
