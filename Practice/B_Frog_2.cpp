#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
    for (int i = 2; i < n; i++) {
        int temp = 1e9;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                temp = min(temp, dp[i - j] + abs(v[i] - v[i - j]));
            }
        }
        dp[i] = temp;
    }
    cout << dp[n - 1];
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
