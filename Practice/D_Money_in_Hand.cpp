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
pair<int, int> arr[100];
int target, n;

int cache[53][50000];
int rec(int level, int money) {
    if (level == 0) {
        return money == 0;
    }
    if (cache[level][money] != -1) return cache[level][money];
    int ans = 0;
    for (int j = 0; j <= arr[level].second; j++) {
        // how much arr[level].first * j we can take
        if (money - arr[level].first * j >= 0) {
            arr[level].second -= j;
            ans |= rec(level - 1, money - (arr[level].first * j));
            arr[level].second += j;
        }
    }
    return cache[level][money] = ans;
}

void solve() {
    cin >> n >> target;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    memset(cache, -1, sizeof(cache));
    if (rec(n, target)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
