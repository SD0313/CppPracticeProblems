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
        string s;
        cin >> s;
        string alpha ("abcdefghijklmnopqrstuvwxyz");
        string curr = "";
        // cout << alpha << ", " << curr << endl;
        bool printed = false;
        int inc = 0;
        for (char c : alpha) {
            if (inc == s.length()) break;
            inc++;
            string p1 = curr + c;
            string p2 = c + curr;
            if (s.find(p1) != string::npos) {
                curr = p1;
            }
            else if (s.find(p2) != string::npos) {
                curr = p2;
            }
            else {
                printed = true;
                cout << "NO" << endl;
                break;
            }
        }
        if (!printed) cout << "YES" << endl;

    }
    
    return 0;
}