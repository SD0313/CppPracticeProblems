#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;
    while (t--) {
        int m; cin >> m;
        string in;
        cin >> in;
        // cout << in << endl;
        unordered_set<char> letters;
        char prev;
        bool sus = false;
        for (int i = 0; i < in.length(); i++) {
            if (letters.find(in[i]) != letters.end()) {
                if (in[i] != prev) {
                    cout << "NO" << endl;
                    sus = true;
                    break;
                }
            }
            letters.insert(in[i]);
            prev = in[i];

        }
        if (!sus) {
            cout << "YES" << endl;
        }
    }

    return 0;

}
