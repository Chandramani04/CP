#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
int dp[4001];
int rec(int n, int a, int b, int c) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return -1e9;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = 1 + max({rec(n - a, a, b, c), rec(n - b, a, b, c), rec(n - c, a, b, c)});
}
void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    // cout << rec(n, a, b, c);
    vector<int> dp(n + 1, 0);
    // dp[0] = 1;
    for (int i = min({a, b, c}); i <= n; i++) {
       dp[i] = max({dp[i - a], dp[i - b], dp[i - c]}) + 1; 
    }
    cout << dp[n];
}
signed main() {
    memset(dp, -1, sizeof(dp));
    int testcase = 1;
    while (testcase--)
        solve();
}
