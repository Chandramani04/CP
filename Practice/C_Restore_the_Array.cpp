#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/

void solve() {
    int n;
    cin >> n;
    vector<int> v(n - 1);
    for (auto &x : v) cin >> x;
    cout << v[0] << " ";
    for (int i = 0; i < n - 2; i++) {
        cout << min(v[i], v[i + 1]) << " ";
    }
    cout << v[n - 2] << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
