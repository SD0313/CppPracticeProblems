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
const int INF = 1e9;


vi make_digits(string num) {
    vi digits;
    for (char i : num) {
        digits.push_back(char_to_int(i));
    }
    return digits;
}


int main() {
    fastio;
    int n; cin >> n; 
    string num = str(n);
    vi digits;
    vi dp(n+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int min_val = INF;
        digits = make_digits(str(i));
        for (int d : digits) {
            min_val = min(min_val, dp[i-d]);
        }
        dp[i] = min_val+1;
    }
    cout << dp[n] << endl;
    return 0;
}