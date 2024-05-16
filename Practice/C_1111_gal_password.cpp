#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 998244353;
void solve() {
    int len;
    cin >> len;
    int n;
    n = len;
    int dp[n + 1][10];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            if (j > 1) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] %= mod;
            }
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if (j < 9) {
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
