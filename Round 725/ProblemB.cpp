#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> vals;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            sum+=k;
            vals.push_back(k);

        }
        if (sum%n != 0) {
            cout << -1 << endl;
            continue;
        }
        int end_val = sum/n;
        int ans=0;
        for (int i: vals){
            if (i > end_val) ans++;
        }
        cout << ans << endl;
    }


    return 0;
}