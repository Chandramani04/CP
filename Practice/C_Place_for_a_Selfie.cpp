#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(),v.end());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int id = lower_bound(v.begin(), v.end(), b) - v.begin();
        if (id < n and (v[id] - b) * (v[id] - b) < 4 * a * c) {
            cout << "YES" << endl;
            cout << v[id] << endl;
            continue;
        }
        if (id > 0 and (v[id - 1] - b) * (v[id - 1] - b) < 4 * a * c) {
            cout << "YES" << endl;
            cout << v[id - 1] << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    cout << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
