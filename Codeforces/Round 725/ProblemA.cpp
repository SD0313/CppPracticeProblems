#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> stones;
        int n; cin >> n;
        int min_val_ind = -1;
        int min_val = INF;
        int max_val = -1;
        int max_val_ind = -1;
        for (int i = 0; i < n ;i++) {
            int k; cin >> k;
            stones.push_back(k);
            if (k < min_val) {
                min_val_ind = i;
                min_val = k;
            }
            if (k > max_val) {
                max_val_ind = i;
                max_val = k;
            }
        }
        int mid = n/2;
        int option1 = max(min_val_ind, max_val_ind)+1;
        int option2 = n-min(min_val_ind, max_val_ind);
        int first_half = min(min_val_ind, max_val_ind);
        int sec_half = max(min_val_ind, max_val_ind);
        int option3 = first_half+1+n-sec_half;
        cout << min(option1, min(option2, option3)) << endl;

    }


    return 0;
}