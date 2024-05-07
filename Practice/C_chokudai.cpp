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

int dp[10005][10];
map<pair<int, string>, int> mp;
int rec(int i, string &str, string &target, string &cur) {
    int n = str.size();
    if (cur.size() == target.size()) {
        if (cur == target) return 1;
        return 0;
    }
    if (i == n) {
        return cur == target;
    }
    if(mp.count({i,cur}))return mp[{i,cur}];
    // take
    int nottake = rec(i + 1, str, target, cur);
    cur.push_back(str[i]);
    int take = rec(i + 1, str, target, cur);
    cur.pop_back();
    int ans = (take % mod + nottake % mod) % mod;
    // return ans;
    return mp[{i,cur}] = ans;
    // not take
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    string target = "chokudai";
    string cur = "";
    memset(dp, -1, sizeof(dp));
    cout << rec(0, s, target, cur) << endl;
}
signed main() {
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        solve();
}
