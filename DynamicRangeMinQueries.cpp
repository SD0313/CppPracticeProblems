#include <bits/stdc++.h>
using namespace std;


// typedef long long LL;
const int INF = 1e9;
struct SegmentTree {
    int size;
    vector<int> tree;
    int func(int a, int b) { return min(a, b);}
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size-1, INF);
    }
    
    void set(int i, int v, int x, int lx, int rx) {
        if (rx-lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if (i < m) set(i, v, 2*x+1, lx, m);
        else set(i, v, 2*x+2, m, rx);
        tree[x] = func(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) {set(i, v, 0, 0, size);}
    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return INF;
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

    // auto func = [](int a, int b) -> int {return min(a, b);};
    int n, q;
    cin >> n >> q;
    SegmentTree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.set(i, v);
    }
    // st.print();
    while (q--) {
        int key, val1, val2;
        cin >> key >> val1 >> val2;
        if (key == 1) st.set(val1, val2);
        else cout << st.query(val1, val2) << endl;
    }

    return 0;
}

