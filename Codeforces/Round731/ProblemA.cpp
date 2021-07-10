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
        int xa, ya, xb, yb, xf, yf;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
        if (xa == xb and xf == xa and (yf-ya)*(yf-yb) < 0) cout << abs(ya-yb) + 2 << endl;
        else if (ya == yb and yf == ya and (xf-xa)*(xf-xb) < 0) cout << abs(xa-xb)+2 << endl;
        else cout << abs(ya-yb) + abs(xa-xb) << endl;
    }
    
    return 0;
}