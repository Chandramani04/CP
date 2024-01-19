#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/

int lcs(string &s, string &v) {
    // find longest common subsequence of two strings in c++
    // https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
    int n = s.size(), m = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i - 1] == v[j - 1]) dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
        }
    return dp[n][m];
}
int lis(vector<int> &arr) {
    // find longest increasing subsequence of an array in c++
    // https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
    int n = arr.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

void solve() {
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    set<int> st(v.begin(), v.end());

    // remove everything and add one elements
    int ans = n * c + d;

    // we must remove repeated values at any cost
    int repeat = n - st.size();
    repeat *= c;

    v.clear();
    v = vector<int>(st.begin(), st.end());
    n = v.size();
    st.clear();

    vector<int> del(n, 0), add(n, 0);

    for (int i = 0; i < n; i++) {
        del[i] = n - 1 - i;
        if (i) {
            add[i] = add[i - 1] + v[i] - v[i - 1] - 1;
        } else
            add[i] = v[i] - 1;
    }

    int cnt = 1e18;

    for (int i = 0; i < n; i++) {
        int cost = repeat + del[i] * c + add[i] * d;
        cnt = min(cnt, cost);
    }

    ans = min(ans, cnt);
    cout << ans << endl; 
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
