#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int sum = v[0] + v[n - 1];
    vector<pair<int, int>> ans;
    if (sum & 1) {
        ans.push_back({1, n});
        v[n - 1] = v[0];
    } else {
        ans.push_back({1, n});
        v[0] = v[n - 1];
    }
    vector<int> odd, even;
    for (int i = 1; i < n - 1; i++) {
        if (v[i] & 1)
            odd.push_back(i + 1);
        else
            even.push_back(i + 1);
    }
    if (v[n - 1] & 1) {
        for (auto x : odd) {
            ans.push_back({x, n});
        }
        for (auto x : even) {
            ans.push_back({1, x});
        }
    } else {
        for (auto x : even) {
            ans.push_back({x, n});
        }
        for (auto x : odd) {
            ans.push_back({1, x});
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
