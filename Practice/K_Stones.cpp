#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
bool dp[100010];
void solve() {
    int n, piles;
    cin >> n >> piles;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // dp[i] = true if we are in winning state else false
    for (int i = 0; i <= piles; i++) {
        bool is_loosing_state = false;
        for (int j = 0; j < n; j++) {
            if (i - arr[j] >= 0) {
                if (dp[i - arr[j]] == false) {
                    is_loosing_state = true;
                    break;
                }
                // if we found a state where we can make the opponent loose then we are in winning state
            }
        }
        dp[i] = is_loosing_state;
    }

    if (dp[piles]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
