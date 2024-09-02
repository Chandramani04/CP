#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }
    sort(v.begin(), v.end());
    vector<int> store;
    for (int k = 0; k < n / 2; k++) {
        store.push_back(v[k]);
        store.push_back(v[(k + n / 2)]);
    }

    auto check = [&](vector<int> store) {
        // either store[i]>store[i-1] and store[i]>store[i+1]   or store[i]<store[i-1] and store[i]<store[i+1]
        for (int i = 1; i < n - 1; i++) {
            if ((store[i] > store[i - 1] && store[i] > store[i + 1]) || (store[i] < store[i - 1] && store[i] < store[i + 1])) {
                continue;
            } else {
                return false;
            }
        }
        if ((store[0] < store[1] and store[0] < store[n - 1]) or store[0] > store[1] and store[0] > store[n - 1]) {
            return true;
        }
        return false;
    };
    if (check(store)) {
        cout << "YES" << endl;
        for (auto x : store) cout << x << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
