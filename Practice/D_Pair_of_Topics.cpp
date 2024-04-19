#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    // good pair => a[i] + a[j] > b[i] + b[j]
    // a[i] - b[i] > b[j] - a[j]
    // a[i]-b[i] > -(a[j]-b[j])
    // 4 8 2 6 2
    // 4 5 4 1 3
    // 0 3 -2 5 -1  a[i]-b[j]
    // 0 1 1 3  2

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int cnt = 0;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = a[i] - b[i];
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < n; i++) {
        int req = (-1 * d[i]) + 1;
        auto it = lower_bound(d.begin(), d.end(), req);
        if (it != d.end()) {
            int id = it - d.begin();
            cnt += n - id;
            if (d[i] >= req) cnt--;
        }
    }
    cout << cnt / 2 << endl;
}
signed main() {
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        solve();
}
