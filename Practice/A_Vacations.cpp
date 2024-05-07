#include "bits/stdc++.h";
using namespace std;
#define int long long
/*void bestSolution() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int dp[n + 1][3];
    memset(dp, 0, sizeof(dp));

    // dp[i][0] --> rest
    // dp[i][1] --> gym
    // dp[i][2] --> contest
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][0]));
        if (a[i] == 2 || a[i] == 3) {
            dp[i][1] = 1 + max(dp[i - 1][0], dp[i - 1][2]);
        }
        if (a[i] == 1 || a[i] == 3) {
            dp[i][2] = 1 + max(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    cout << n - max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}
*/
/*--------------------------------------------------------------------------------------------------*/

int N;
int days[101];
int cache[101][2][2][2];

int rec(int i, int rest, int contest, int gym) {
    if (i == N) return 0;
    if (cache[i][rest][contest][gym] != -1) return cache[i][rest][contest][gym];
    int ans;
    if (days[i] == 0) {
        // only option is to rest
        ans = rec(i + 1, 1, 0, 0);
    } else if (days[i] == 1) {
        // rest
        ans = rec(i + 1, 1, 0, 0);
        // give contest if only yesterday didn't gave contest
        if (contest == 0) {
            ans = max(ans, 1 + rec(i + 1, 0, 1, 0));
        }
    } else if (days[i] == 2) {
        // rest
        ans = rec(i + 1, 1, 0, 0);
        // give gym if only yesterday didn't gave gym
        if (gym == 0) {
            ans = max(ans, 1 + rec(i + 1, 0, 0, 1));
        }
    } else {
        // rest
        ans = rec(i + 1, 1, 0, 0);
        // give contest if only yesterday didn't gave contest
        if (contest == 0) {
            ans = max(ans, 1 + rec(i + 1, 0, 1, 0));
        }
        // give gym if only yesterday didn't gave gym
        if (gym == 0) {
            ans = max(ans, 1 + rec(i + 1, 0, 0, 1));
        }
    }
    return cache[i][rest][contest][gym] = ans;
}
/*
days[i] = 0 --> gym close , contest close
days[i] = 1 --> gym close , contest happened
days[i] = 2 --> gym open , contest close
days[i] = 3 --> gym open , contest happened
*/
int iter() {
    int dp[101][2][2][2];
    memset(dp, 0, sizeof(dp));
    for (int i = N - 1; i >= 0; i--) {
        for (int rest = 0; rest < 2; rest++) {
            for (int contest = 0; contest < 2; contest++) {
                for (int gym = 0; gym < 2; gym++) {
                    int &ans = dp[i][rest][contest][gym];
                    if (days[i] == 0) {
                        ans = dp[i + 1][1][0][0];
                    } else if (days[i] == 1) {
                        ans = dp[i + 1][1][0][0];
                        if (contest == 0) {
                            ans = max(ans, 1 + dp[i + 1][0][1][0]);
                        }
                    } else if (days[i] == 2) {
                        ans = dp[i + 1][1][0][0];
                        if (gym == 0) {
                            ans = max(ans, 1 + dp[i + 1][0][0][1]);
                        }
                    } else {
                        ans = dp[i + 1][1][0][0];
                        if (contest == 0) {
                            ans = max(ans, 1 + dp[i + 1][0][1][0]);
                        }
                        if (gym == 0) {
                            ans = max(ans, 1 + dp[i + 1][0][0][1]);
                        }
                    }
                }
            }
        }
    }
    return N - dp[0][1][0][0];
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> days[i];
    }
    cout << iter() << endl;
    return;
    // memset(cache, -1, sizeof(cache));
    // cout << N - rec(0, 1, 0, 0) << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
