#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int tsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        tsum += v[i];
    }
    if (tsum % 3 == 0) {
        cout << 0 << endl;
        return;
    }
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = v[i] % 3;
    }
    int cnt0 = 0, cnt2 = 0, cnt1 = 0;
    for (auto x : temp) {
        if (x == 0)
            cnt0++;
        else if (x == 1)
            cnt1++;
        else
            cnt2++;
    }

    int cmd = 0;
    for (auto x : temp) cmd += x;
    if (cmd % 3 == 1) {
        if (cnt1 > 0) {
            cout << 1 << endl;
        } else {
            cout << min(n, 2ll) << endl;
        }
    } else {
        cout << 1 << endl;
    }
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
