#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
    for (int i = 2; i < n; i++) {
        int onejump = dp[i - 1] + abs(v[i] - v[i - 1]);
        int twojump = dp[i - 2] + abs(v[i] - v[i - 2]);
        dp[i] = min(onejump, twojump);
    }
    cout << dp[n - 1];
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
