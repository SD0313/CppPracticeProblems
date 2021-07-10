#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(int n) {
    string num = to_string(n);
    string s = "";
    for (int i = 0; i < num.size()-1; i++) {
        s += "1";
    }
    s += "0";
    int total = stoi(s);
    for (int i = 0; i  < num.size(); i++) {
        int pos = num.size()-i-1;
        ll to_add = 1;
        for (int j = 0; j < pos; j++) {
            to_add *= 10;
        }
        total += ((s[i]-'0')-1)*to_add;
    }
    return total;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        cout << solve(r)-solve(l) << endl;
    }



    return 0;
}