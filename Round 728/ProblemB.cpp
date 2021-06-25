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

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vl arr;
        vi maxes(n);
        vi mines(n);
        for (int i = 0; i < n; i++) {
            int other_ind = n-i-1;
            int k; cin >> k;
            arr.pb(k);
            if (i == 0) {
                maxes[other_ind] = k;
                mines[other_ind] = k;
            }
            else {
                mines[other_ind] = min(mines[other_ind+1], k);
                maxes[other_ind] = max(maxes[other_ind+1], k);
            }
        }
        // for (ll& k : arr) {
        //     cin >> k;
        // }
        // PRINT(arr);
        int total = 0;
        for (int i = 1; i < n; i++) {
            int min_bound = i+i+1;
            int max_bound = i+n;
            int min_val_bound = (min_bound%arr[i-1] == 0) ? (int) min_bound/arr[i-1] : (int) min_bound/arr[i-1]+1;
            int max_val_bound = (int) max_bound/arr[i-1];
            if (maxes[i-1] < max_val_bound) continue;
            if (mines[i-1] > min_val_bound) continue;
            for (int j = i+1; j <= n; j++) {
                if (i+j == arr[i-1]*arr[j-1]) total++;
            }
        }
        cout << total << endl;

    }

    
    return 0;
}