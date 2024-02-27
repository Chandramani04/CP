#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int count_gcd = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        count_gcd = __gcd(count_gcd, v[i]);
    }
    int ans = count(v.begin(), v.end(), count_gcd);
    if (ans > 1) {
        cout << "NO" << endl;
    } else
        cout << "YES" << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
