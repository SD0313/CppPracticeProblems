#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;
#define pb push_back
#define str to_string
#define PRINT(vec) for (auto i : vec) {cout << i << " ";} cout << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd __gcd
#define lcm(a, b) a*b/gcd(a, b)


vi get_prime_factors(int n) {
    vi out;
    int up = (int) sqrt(n);
    for (int i = 2; i <= up; i++) {
        while (n%i == 0) {
            out.pb(i);
            n /= i;
        }
    }
    if (n != 1) out.pb(n);
    return out;
}


int get_max_steps(int n) {
    vi prime_factors = get_prime_factors(n);
    // PRINT(prime_factors);
    int total = prime_factors.size();

    return total;
}



int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        int total_steps = get_max_steps(a) + get_max_steps(b);
        if (k == 1 && ((gcd(a, b) != a && gcd(a, b) != b) || total_steps < 1)) cout << "NO" << endl;
        else if (k == 1 && a == b) cout << "NO" << endl;
        else if (k == 1) cout << "YES" << endl;
        else if (total_steps >= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}