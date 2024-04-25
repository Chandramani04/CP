#include "bits/stdc++.h";
using namespace std;
#define int long long

int dp[602][603][603];
// map<tuple<int, int, int>, int> mp;
map<pair<int, int>, int> mp;
int rec(vector<string>& str, int i, int m, int n) {
    string s = str[i];
    // if current subset is choosen
    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = count(s.begin(), s.end(), '1');
    if (i == 0) {
        if (n == cnt1) {
            if (m >= cnt0) return 1;  // take the subset
        }
        if (n == 0) {
            return 0;
        }
        return -1e9;
    }
    if (mp.find({i, n}) != mp.end()) return mp[{i, n}];
    // if (dp[i][m][n] != -1) return dp[i][m][n];
    int notpick = rec(str, i - 1, m, n);
    int pick = -1e9;
    if (cnt1 <= n and cnt0 <= m) {
        pick = 1 + rec(str, i - 1, m - cnt0, n - cnt1);
    }
    return  mp[{i, n}] = max(pick, notpick);
}

// 3 1 1

int findMaxForm(vector<string>& str, int m, int n) {
    int l = str.size();
    memset(dp, -1, sizeof(dp));
    return rec(str, l - 1, m, n);
}
void solve() {
    int l, m, n;
    cin >> l;
    vector<string> strs(l);
    for (auto& x : strs) cin >> x;
    cin >> m >> n;

    cout << findMaxForm(strs, m, n);
}
signed main() {
    int testcase = 1;
    while (testcase--) solve();
}
