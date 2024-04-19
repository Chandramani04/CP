#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/

// dp[i] = min buttons to be pressed to reach i
// dp[n] = 0
// for i = 1 to n - 1 dp[i] = n - i
// for i = n + 1 to  m  if(i & 1 ) dp[i]  = dp[(i+1)/2] + 2 else dp[i] = dp[i/2] + 1
int dp[1000010];
void solve() {
    int n, m;
    cin >> n >> m;
    dp[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = n - i;
    }
    for (int i = n + 1; i <= m; i++) {
        if (i & 1) {
            dp[i] = dp[(i + 1) / 2] + 2;
        } else {
            dp[i] = dp[i / 2] + 1;
        }
    }
    cout << dp[m] << endl;
    // for (int i = 1; i <= max(n, m); i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
