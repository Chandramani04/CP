#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
// If the last two digits of a number are divisible by 4, then that number is a multiple of 4 and is divisible by 4 completely.
void solve() {
    string s;
    cin >> s;
    // count the no of substring that are divisible by 4
    // 124
    // if(s[i]%4==0)dp[i]=dp[i-1]+1;
    // if(last 2 digits are divisible by 4) last 2 characters are fixed ,
    // all the characters that are before the last 2 characters are is our answer ie. i-1

    // dp[1] = 0
    // dp[2] = 1
    // dp[3] = 2 + 1 = 3
    // dp[i] = #substring divisible by 4 ending at i
    int n = s.size();
    int dp[n + 1];
    fill(dp, dp + n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if ((s[i - 1] - '0') % 4 == 0) {
            dp[i] += 1;
        }
        if (i >= 2) {
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (num % 4 == 0) {
                dp[i] += i - 1;
            }
        }
        dp[i] += dp[i - 1];
    }
    cout << dp[n] << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
