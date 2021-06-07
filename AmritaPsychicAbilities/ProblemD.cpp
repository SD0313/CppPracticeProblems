#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    typedef set<int> Set;
    int size;
    vector<Set> tree;
    Set empty = {};
    Set func(Set a, Set b) { 
        Set output;
        set_union(a.begin(), a.end(),
        b.begin(), b.end(),
        inserter(output, output.begin()));
        return output;
    }
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size-1, empty);
    }
    
    void set(int i, Set v, int x, int lx, int rx) {
        if (rx-lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if (i < m) set(i, v, 2*x+1, lx, m);
        else set(i, v, 2*x+2, m, rx);
        tree[x] = func(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) {
        Set v_set = {v};
        set(i, v_set, 0, 0, size);
    }
    int query(int l, int r) {
        Set ans = query(l, r, 0, 0, size);
        return ans.size();
    }
    Set query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return empty;
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx)/2;
        return func(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int n, q;
    cin >> n >> q;
    SegmentTree tree;
    tree.init(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        tree.set(i, v);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << tree.query(l-1, r) << "\n";
    }
    return 0;
}
