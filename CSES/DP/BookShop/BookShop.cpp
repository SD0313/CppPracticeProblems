#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;
#define pb push_back
#define str to_string
#define char_to_int(c) c-'0'
#define mp make_pair
#define PRINT(vec) for (auto i : vec) {cout << i << " ";} cout << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd __gcd
#define lcm(a, b) a*b/gcd(a, b)

int main() {
    fastio;
    int n, x;
    cin >> n >> x;
    vi prices(n), pages(n);
    for (int& k : prices) cin >> k;
    for (int& k : pages) cin >> k;
    PRINT(prices);
    PRINT(pages);
    vi dp(x+1, 0);
    for (int i = 1; i < x+1; i++) {
        int curr_max = dp[i-1];
        for (int j = 0; j < n; j++) {
            if (i-prices[j] >= 0) {
                curr_max = max(dp[i-prices[j]]+pages[j], curr_max);
            }
        }
        dp[i] = curr_max;
    }
    for (int i = 0; i < x+1; i++) {
        cout << i << " ";
    }
    cout << "\n";
    PRINT(dp);
    cout << dp[x] << endl;


    
    return 0;
}