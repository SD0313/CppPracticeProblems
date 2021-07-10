#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;
#define pb push_back
#define str to_string
#define PRINT(vec) for (auto i : vec) {cout << i << " ";} cout << "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


/*recursive option
ll solve(int n, ll total) {
    string num = str(n);
    if (num.size() == 1) {
        return total + n;
    }
    total += (n%10) + 10 * (int) (n/10);
    return solve(stoi(num.substr(0, num.size()-1)), total);
}
*/

//dp option
ll solve_dp(int n) {
    vl dp;
    dp.pb(0);
    string num = str(n);
    int length = num.size();
    int i = 0;
    while (length--) {
        dp.pb(dp[i++] + (n%10) + 10 * (int) (n/10));
        if (length) {
            num = num.substr(0, num.size()-1);
            n = stoi(num);
        }
    }
    return dp[dp.size()-1];
}
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << solve_dp(r)-solve_dp(l) << endl;
    }
    return 0;
}