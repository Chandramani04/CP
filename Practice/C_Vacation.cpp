#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    // state -> dp[i][j] means maximum happiness we can get till ith day by performing jth operation
    for (int i = 1; i < n; i++) {
        // if he performs 0th activity then he must have not performed 0th activity on i-1th day
        dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
        // if he performs 1st activity then he must have not performed 1st activity on i-1th day
        dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
        // if he performs 2nd activity then he must have not performed 2nd activity on i-1th day
        dp[i][2] = arr[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
