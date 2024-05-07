#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
// use boolean done array for memoization , if done[i][j] = true then it means that the value of dp[i][j] is already calculated
//  Dp forms ->
// 1. dp[i][j] = best ans from i to n if prev_ans = j
// 2.Ending Form -> dp[i][j] = best answer ending at index i with prev_ans = j
// 3.Multisequence dp -> LCS problems -> dp[i][j] = best ans from 0 to i of array A and 0 to j of array B
// 4.LRdp / Interval Dp -> Rod cutting problems -> rec(l,r){cost of cutting the rod from l to r } = min(rec(l,i) + rec(i,r) + cost(l,r))
int n, x;
int price[1001], page[1001];
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> page[i];
    }
    // dp[i][x] = maximum page you can get by spending x money from 0 to i books
    int dp[n + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int money = 0; money <= x; money++) {
            int notBuy = dp[i - 1][money];
            int buy = 0;
            if (money - price[i] >= 0) {
                buy = dp[i - 1][money - price[i]] + page[i];
            }
            dp[i][money] = max(notBuy, buy);
        }
    }
    cout << dp[n][x];
}
signed main() {
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        solve();
}
