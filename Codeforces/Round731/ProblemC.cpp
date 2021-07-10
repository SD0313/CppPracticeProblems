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
    int t; cin >> t;
    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;
        vi a(n), b(m);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;
        // PRINT(a);
        // PRINT(b);
        int p1 = 0;
        int p2 = 0;
        // cout << p1 << ", " << p2 << endl;
        vi seq;
        bool printed = false;
        while (p1 < n or p2 < m) {
            if (p1 == n) {
                if (b[p2] > k) {
                    cout << -1 << endl;
                    printed = true; break;
                }
                seq.pb(b[p2]); 
                if (b[p2] == 0) k++;
                p2++;
                continue;
            }
            else if (p2 == m) {
                if (a[p1] > k) {
                    cout << -1 << endl;
                    printed = true; break;
                }
                seq.pb(a[p1]); 
                if (a[p1] == 0) k++;
                p1++;
                continue;
            }
            if (a[p1] == 0) {
                seq.pb(a[p1]);
                p1++; k++; continue;
            }
            if (b[p2] == 0) {
                seq.pb(b[p2]);
                p2++; k++; continue;
            }
            if (a[p1] <= b[p2]) {
                if (a[p1] > k) {
                    cout << -1 << endl;
                    printed = true; break;
                }
                seq.pb(a[p1++]);
            }
            else {
                if (b[p2] > k) {
                    cout << -1 << endl;
                    printed = true; break;
                }
                seq.pb(b[p2++]);
            }
        }
        if (!printed) {
            for (int c : seq) cout << c << " ";
            cout << "\n";
        }

        /*vi comb(n+m);
        for (int i = 0; i < n+m; i++) {
            if (i < n) comb[i] = a[i];
            else comb[i] = b[i-m];
        }
        sort(comb.begin(), comb.end());
        PRINT(comb);
        cout << "======================" << endl;

        do {
            PRINT(comb);
        } while (next_permutation(comb.begin(), comb.end()));*/
    }

    
    return 0;
}