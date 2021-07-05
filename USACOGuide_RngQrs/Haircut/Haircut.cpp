//Author: Sauman Das
//Date: 6/30/2021
//Comments: This solution uses segment trees, but it can also be done using BITs.


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
    vector<int> tree;
    int func(int a, int b) { return a+b;}
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size-1, 0);
    }
    
    void set(int i, int v, int x, int lx, int rx) {
        if (rx-lx == 1) {
            tree[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        if (i < m) set(i, v, 2*x+1, lx, m);
        else set(i, v, 2*x+2, m, rx);
        tree[x] = func(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int inc) {set(i, inc, 0, 0, size);}
    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx)/2;
        return func(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
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
    freopen("haircut.in","r",stdin);
	freopen("haircut.out","w",stdout);
    int n;
    cin >> n;
    vi hair(n);
    for (int& k : hair) cin >> k;
    // PRINT(hair);
    SegmentTree seg;
    seg.init(n+2);
    vl inv(n+1, 0);
    for (int i : hair) {
        inv[i] += seg.query(i+1, seg.size);
        seg.set(i, 1);
    }
    cout << 0 << endl;
    ll total = 0;
    for (int i = 0; i < n-1; i++) {
        total += inv[i];
        cout << total << endl;
    }
    return 0;
}