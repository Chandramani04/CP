#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    vector<int> arr;
    for (int i = n / 2; i < n; i++) {
        arr.push_back(v[i]);
    }
    auto check = [&](int mid) {
        int req = 0;
        for (auto x : arr) {
            req += mid - x;
            if (req > k) return false;
            // req += max(0ll,mid - x);
        }
        return req <= k;
    };

    int low = v[0], high = 1e18;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        // can we make mid a median
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << low << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
