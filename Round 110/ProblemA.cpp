#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--) {
        int n1, n2, n3, n4;
        cin >> n1 >> n2 >> n3 >> n4;
        if (max(n1, n2) < min(n3, n4) || max(n3, n4) < min(n1, n2)) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}