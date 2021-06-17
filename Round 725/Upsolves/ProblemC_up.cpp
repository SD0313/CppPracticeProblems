#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
#define pb push_back;
#define PRINT(vec) for (int i : vec) {cout << i << " ";} cout << "\n";;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        // cout << n << l << r << endl;
        vi arr(n);
        for (int& a : arr) {
            cin >> a;
        }
        sort(arr.begin(), arr.end());
        // PRINT(arr);
        ll total = 0;
        for (int i = 0; i < n-1; i++) {
            ll lo_b, up_b;
            auto start = arr.begin();
            advance(start, i+1);
            auto low = lower_bound(start, arr.end(), l-arr[i]);
            if (low-arr.begin() == n) continue;
            auto up = upper_bound(start, arr.end(), r-arr[i]);
            total += up-arr.begin()-(low-arr.begin());
        }
        cout << total << endl;
    }

    return 0;
}