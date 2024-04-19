#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
double dp[3000][3000];
void solve() {
    int n;
    cin >> n;
    double arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // dp[i][j] = probability of getting j heads in i coins
    // float dp[n][n + 1];
    // memset(dp,0,sizeof(dp));
    // possibilities for 1st coin
    dp[0][0] = 1.0 - arr[0];
    dp[0][1] = arr[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3000; j++) {
            // tail
            dp[i][j] += dp[i - 1][j] * (1 - arr[i]);
            // head
            if (j > 0) {
                // head aaaya to
                dp[i][j] += dp[i - 1][j - 1] * arr[i];
            }
        }
    }
    double ans = 0;
    for (int i = n / 2 + 1; i < 3000; i++) {
        ans += dp[n - 1][i];
    }
    cout << setprecision(10) << fixed << ans << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
