#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
int dp[1000110];
// dp[i] = moves req to make i zero
vector<int> digits(int n) {
    vector<int> d;
    while (n) {
        if (n % 10 > 0) d.push_back(n % 10);
        n /= 10;
    }
    return d;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < 10; i++) {
        dp[i] = 1;
    }
    for (int i = 10; i <= n; i++) {
        // dp[i] = minimum moves req to make current i zero
        dp[i] = 1e9;
        vector<int> d = digits(i);
        for (auto x : d) {
            dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    cout << dp[n] << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
