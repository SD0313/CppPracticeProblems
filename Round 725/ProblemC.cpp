#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool check(LL sum, int l, int r) {
    return sum >= l && sum <= r;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<LL> dp;
        for (int i = 0; i < n; i++) {
            LL k; cin >> k;
            dp.push_back(k);
        }
        sort(dp.begin(), dp.end());
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        int real_ans = 0;
        for (int i = 0; i < n-1; i++) {

            LL v1 = dp[i];
            // if (v1 > r) continue;
            int lo = i+1;
            int hi = n-1;
            for (hi++; lo < hi;) {
                int mid = lo+(hi-lo)/2;
                if (dp[mid]+v1 >= l) hi = mid;
                else lo = mid+1;
            }
            int low_bound = lo;
            lo = i;
            hi = n-1;
            for (--lo; lo < hi;) {
                int mid = lo+(hi-lo+1)/2;
                if (dp[mid]+v1 <= r) lo = mid;
                else hi = mid-1;
            }
            int hi_bound = lo;
            if (!(hi_bound <= i || low_bound >= n)){
                ans += hi_bound-low_bound+1;
            }
            /*for (int j = i+1; j < n; j++) {
                int sum = dp[i]+dp[j];
                if (check(sum, l, r)) {
                    real_ans++;
                }
                else if (sum > r) {
                    break;
                }
            }*/
        }
        cout << ans << endl;
        // cout << "My Answer: " << ans << " Real Answer: " << real_ans << endl;


    }



    return 0;
}