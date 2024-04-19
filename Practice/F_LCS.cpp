#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    string s, v;
    cin >> s >> v;
    int n = s.size(), m = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == v[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int lcs = dp[n][m];
    string ans;
    if (lcs == 0) {
        cout << ans << endl;
        return;
    }

    // tracing lcs back
    int i = n, j = m;
    // printing lcs
    while (i > 0 and j > 0) {
        if (s[i - 1] == v[j - 1]) {
            ans.push_back(s[i - 1]);
            i--, j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
