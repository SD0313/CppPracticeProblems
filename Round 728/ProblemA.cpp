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
        vi arr(n);
        if (n == 2) {
            cout << 2 << " " << 1 << endl;
        }
        else if (n == 3) {
            cout << 3 << " " << 1 << " " << 2 << endl;
        }
        else {
            for (int i = 1; i <= n; i+=2) {
                if (i == n-2) {
                    arr[n-3] = n-1; arr[n-2] = n; arr[n-1] = n-2;
                    break;
                }
                else arr[i-1] = i+1; arr[i] = i;
            }
            PRINT(arr);
        }
    }
    
    return 0;
}