#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;

    int p = 0;

    for (int i = 0; i < m; i++) {
        int q = p;
        for (char x = l[i]; x <= r[i]; x++) {
            // if x is not present from p....s.end()  then ans is true
            if (s.find(x, p) == string::npos) {
                cout << "YES" << endl;
                return;
            }
            q = max(q, (int)s.find(x, p) + 1);
        }
        p = q;
    }
    cout << "NO" << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
