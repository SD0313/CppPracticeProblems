#include <bits/stdc++.h>
using namespace std;


bool add1(int first_digit, int n, string num) {
    string s;
    for (int i = 0; i < num.length(); i++) {
        s += to_string(first_digit);
    }
    return stoi(s) <= n;

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string num = to_string(n);
        // cout << num << endl;

        int first_digit = num[0] - '0';
        int total = 9*(num.length()-1)+(first_digit)-1;
        if (add1(first_digit, n, num)) cout << total+1 << endl;
        else cout << total << endl;
        
    }



    return 0;
}

