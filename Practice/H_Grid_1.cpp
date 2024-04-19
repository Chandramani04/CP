#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 and j == 0) {
                // 1st cell
                if (arr[i][j] != '#')
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            } else if (i > 0 and j == 0) {
                if (arr[i][j] == '.') {
                    dp[i][j] = dp[i - 1][j];
                } else
                    dp[i][j] = 0;
            } else if (i == 0 and j > 0) {
                if (arr[i][j] == '.') {
                    dp[i][j] = dp[i][j - 1];
                } else
                    dp[i][j] = 0;
            } else {
                if (arr[i][j] == '.') {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                } else
                    dp[i][j] = 0;
            }
            dp[i][j] %= mod;
        }
    }

    int ans = dp[n - 1][m - 1] % mod;
    cout << ans << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
