#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;

    vector<int> temp(n);
    for (int i = 0; i < n; i++) cin >> temp[i];

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        if (temp[i] < i + 1) {
            v.push_back({temp[i], i + 1});
        }
    }
    if (v.size() == 0) {
        cout << 0 << endl;
        return;
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    n = v.size();

    vector<int> arr;
    for (auto [x, y] : v) {
        arr.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int l = v[i].first, r = v[i].second;
        auto it = upper_bound(arr.begin(), arr.end(), r);
        if (it == arr.end()) continue;
        int idx = it - arr.begin();
        cnt += n - idx;
    }

    cout << cnt << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
