#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;
#define pb push_back
#define str to_string
#define mp make_pair
#define PRINT(vec) for (auto i : vec) {cout << i << " ";} cout << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd __gcd
#define lcm(a, b) a*b/gcd(a, b)

const int MOD = 1e9+7;

int main() {
    fastio;
    int n, x;
    cin >> n >> x;
    vl coins(n);
    for (ll& k : coins) {
        cin >> k;
    }
    // PRINT(coins);
    vl dp(x+1, 0);
    dp[0] = 1;
    for (int i = 0; i < x+1; i++) {
        for (ll c : coins) {
            if (i-c >= 0) {
                dp[i] += dp[i-c]%MOD;
            }
        }
    }
    cout << dp[x]%MOD << endl;
    return 0;
}