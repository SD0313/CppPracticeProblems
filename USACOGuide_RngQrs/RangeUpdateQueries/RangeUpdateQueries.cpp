//Problem Statement: https://cses.fi/problemset/task/1651
//Solution follows approach presented here: https://codeforces.com/edu/course/2/lesson/5

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;
#define pb push_back
#define str to_string
#define mp make_pair
#define PRINT(vec) for (auto i : vec) {cout << i << " ";} cout << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd __gcd
#define lcm(a, b) a*b/gcd(a, b)


struct SegmentTree {
    int size;
    vl tree;
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size-1, 0);
    }
    void rngUpdate(int l, int r, int v) {
        rngUpdate(0, 0, size, l, r, v);
    }
    void rngUpdate(int i, int lx, int rx, int l, int r, int v) {
        if (lx >= l and rx <= r) {
            tree[i] += v;
            return;
        }
        if (rx <= l || r <= lx) return;
        int m = (lx+rx)/2;
        rngUpdate(2*i+1, lx, m, l, r, v); rngUpdate(2*i+2, m, rx, l, r, v);
        // tree[i] = tree[2*i+1] + tree[2*i+2];
    }
    ll get(int k) {
        return get(0, 0, size, k);
    }
    ll get(int i, int lx, int rx, int k) {
        if (k < lx || k >= rx) return 0;
        if (rx-lx == 1) return tree[i];
        int m = (lx+rx)/2;
        return tree[i] + get(2*i+1, lx, m, k) + get(2*i+2, m, rx, k);

    }
    void print() {
        int ind = 0;
        int row_size = 1;
        while (ind < size) {
            for (int i = 0; i < row_size; i++) {
                cout << tree[ind++] << '\t';
            }
            cout << endl;
            row_size *= 2;

        }
    }

};


int main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vl arr(n);
    SegmentTree seg; seg.init(n);
    for (ll& k : arr) {
        cin >> k;
    }
    // PRINT(arr);
    while (q--) {
        int k; cin >> k;
        if (k == 1) {
            // update
            int l, r, v;
            cin >> l >> r >> v;
            seg.rngUpdate(--l, r, v);
            // seg.print();
        }
        if (k == 2) {
            // get value
            int p; cin >> p;
            cout << seg.get(p-1) + arr[p-1] << endl;
        }
    }
    return 0;
}