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
int a[111], b[111];
int cache[101][10001];
int f(int i, int sum) {
    if (i == n) {
        return sum == 0;
    }
    if (cache[i][sum] != -1) {
        return cache[i][sum];
    }
    int aj = f(i + 1, sum - a[i]);
    int bj = f(i + 1, sum - b[i]);
    return cache[i][sum] = aj | bj;
}

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << (f(0, x) ? "Yes" : "No") << endl;
}
signed main() {
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        solve();
}
