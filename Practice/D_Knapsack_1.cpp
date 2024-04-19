#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    // dp[i][w] = maximum value that can be obtained with weight w using first i items
    int dp[n + 1][w + 1];
    // if we have 0 items then we can't get any value
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    //  if we have 0 weight then we can't get any value
    for (int i = 0; i <= w; i++) {
        dp[0][i] = 0;
    }
    // if we take 1st item
    dp[0][weight[0]] = value[0];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            int cw = weight[i - 1], cv = value[i - 1], mw = j;
            // we have maximum alloted weight mw , current weight cw and current value cv
            // can we take this item or not ?
            int take = 0;
            if (mw >= cw) {  // hm current item tbhi le skte hain jb uska weight mw se chota ho
                take = cv + dp[i - 1][mw - cw];
            }
            int nottake = dp[i - 1][j];  // same mw pe i-1 items se kitna value mil rha hai
            dp[i][j] = max(take, nottake);
        }
    }
    cout << dp[n][w] << endl;
}

void again_solve() {
    int n, w;
    cin >> n >> w;
    int weight[n + 1], value[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    // dp[i][w] = till ith item , maximum value that can be obtained with weight w
    // maximum -> initialize with minimum value or 0
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = 0;
        }
    }
    // key notes
    // if finding maximum , initialize with minimum value or vice versa
    // always put value for picking 1 item dp[0][weight[0]] or dp[0][value[0]]
    // answer exists in n-1th row
    // if he takes 1st item
    dp[1][weight[1]] = value[1];

    // if he has 0 weight , then 0 value possible
    // if he has 0 item , then 0 value possilbe
    // both cases covered above during initialization

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            int nottake = dp[i - 1][j];
            int take = 0;
            if (j >= weight[i]) {
                take = value[i] + dp[i - 1][j - weight[i]];
            }
            dp[i][j] = max(take, nottake);
        }
    }
    cout << dp[n][w];
}

signed main() {
    int testcase = 1;
    while (testcase--)
        again_solve();
    // solve();
}
