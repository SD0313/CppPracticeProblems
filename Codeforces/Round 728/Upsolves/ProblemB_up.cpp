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

int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, int> index;
        for (int i = 1; i <= n; i++) {
            int k; cin >> k;
            index.insert(mp(k, i));
        }
        int total = 0;
        for (ll sum = 3; sum <= 2*n-1; sum++) { // sums
            for (ll i = 1; i*i <= sum; i++) { // factors
                if (sum%i == 0) {
                    ll f2 = sum/i;
                    if (index.find(i) != index.end() && index.find(f2) != index.end() && index[f2] + index[i] == sum && index[f2] != index[i]) {
                        total++;
                    }
                }
            }
        }
        cout << total << endl;


    }

    
    return 0;
}