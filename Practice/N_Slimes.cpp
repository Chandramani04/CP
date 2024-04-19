#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
int a[500];
int prefix[500];

int dp[500][500];

int f(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int cost = 1e18;
    for (int k = l; k < r; k++) {
        cost = min(cost, f(l, k) + f(k + 1, r) + prefix[r] - prefix[l - 1]);
    }
    return dp[l][r] = cost;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for(int RminusL = 2;RminusL<=n;RminusL++){
        for(int L = 1;L+RminusL-1<=n;L++){
            int R = L+RminusL-1;
            dp[L][R] = 1e18;
            for(int k = L;k<R;k++){
                dp[L][R] = min(dp[L][R],dp[L][k]+dp[k+1][R]+prefix[R]-prefix[L-1]);
            } 
        }
    }
    cout << dp[1][n] << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
