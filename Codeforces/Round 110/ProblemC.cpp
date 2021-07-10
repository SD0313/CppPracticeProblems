#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL process(string s) {
    LL total = 0;
    int p1 = 0;
    int p2 = 1;
    int last_1_0 = -1;
    while (p1 < s.size()-1) {
        // cout << p1 << ", " << p2 << endl;
        if (p2-p1 == 1) {
            string sub = s.substr(p1, 2);
            // if (!(sub.compare("11") == 0 || sub.compare("00") == 0)) {
            if ((sub.at(0) != sub.at(1)) || sub.at(0) == '?') {
                total++;
                if (s.at(p1) != '?') {
                    last_1_0 = p1;
                }
                else if (s.at(p2) != '?') {
                    last_1_0 = p2;
                }
                p2++;
            }
            else {
                p1++; p2++;
                last_1_0 = -1;
            }
        }
        else {
            char new_char = s.at(p2);
            if (new_char == '?') {
                total++;
                p2++;
            }
            else if ((s.at(p2-1) == '0' && new_char == '1') || (s.at(p2-1) == '1' && new_char == '0')) {
                total++;
                last_1_0 = p2;
                p2++;
            }
            else if (last_1_0 == -1) {
                last_1_0 = p2;
                total++;
                p2++;
            }
            else {
                if ((p2-last_1_0)%2 == 1 && s.at(p2) != s.at(last_1_0)) {
                    total++;
                    last_1_0 == p2;
                    p2++;
                }
                else if ((p2-last_1_0)%2 == 0 && s.at(p2) == s.at(last_1_0)) {
                    total++;
                    last_1_0 == p2;
                    p2++;
                }
                else {
                    p1++;
                    p2 = p1+1;
                }
            }
        }
        if (p2 == s.size()) {
            p1++;
            p2 = p1+1;
            last_1_0 = -1;
        }
    }


    return total+s.size();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // cout << s << endl;
        if (s.size() == 1) {
            cout << 1 << endl;
        }
        else {
            cout << process(s) << endl;
        }
    }


    return 0;
}