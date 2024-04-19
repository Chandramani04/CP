#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int k;
    cin >> k;
    vector<int> b(k);
    for (int &x : b) cin >> x;

    auto get = [&](auto a) {
        vector<pair<int, int>> b;
        for (int i = 0; i < (int)a.size(); i++) {
            int cnt = 1;
            int x = a[i];
            while (x % m == 0) {
                cnt *= m;
                x /= m;
            }
            if (b.empty()) {
                b.push_back({x, cnt});
            } else {
                if (b.back().first == x) {
                    b.back().second += cnt;
                } else {
                    b.push_back({x, cnt});
                }
            }
        }
        return b;
    };

    if (get(a) == get(b)) {
        cout << "Yes" << endl;
    } else
        cout << "No" << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
