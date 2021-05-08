//successful solution for https://cses.fi/problemset/task/1648/

#include <bits/stdc++.h>
using namespace std;


typedef long long LL;

struct FenwickTree {
    int size;
    vector<LL> bit;
    vector<int> arr;
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        bit.assign(size, 0LL);
        arr.assign(size, 0);
    }
    int lsb(int i) {return i&-i;}
    long sum(int a, int b) {
        return (a != 1) ? sum(b)-sum(a-1) : sum(b);
    }
    void set(int k, int x) {
        add(k, x-arr[k-1]);
        arr[k-1] = x;
    }
    void add(int k, int x) {
        k--;
        while (k < size) {
            bit[k] += x;
            k += lsb(k+1);
        }
    }
    long sum(int k) {
        long s = 0;
        k--;
        while (k >= 0) {
            s += bit[k];
            k -= lsb(k+1);
        }
        return s;
    }        
};

int main() {
    int n, q;
    cin >> n >> q;
    FenwickTree ft;
    ft.init(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        ft.set(i+1, v);
    }
    while (q--) {
        int key, val1, val2;
        cin >> key >> val1 >> val2;
        if (key == 1) ft.set(val1, val2);
        else cout << ft.sum(val1, val2) << endl;
    }
    return 0;
}
