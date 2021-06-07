#include <bits/stdc++.h>
using namespace std;

int num_good_pairs(vector<int> v) {
    int total = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            int div = __gcd(v[i], 2*v[j]);
            if (div != 1) total++;
        }
    }
    return total;
} 

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        while (n--) {
            int a;
            cin >> a;
            if (a%2 == 0) {
                v.insert(v.begin(), a);
            }
            else {
                v.push_back(a);
            }
        }
        cout << num_good_pairs(v) << endl;
    }



    return 0;
}