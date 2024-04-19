#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        mp[b[i]] = i;
    }
    int moves[n + 1];
    memset(moves, 0, sizeof(moves));
    for (int i = 1; i <= n; i++) {
        int loc = mp[a[i]];
        if (loc >= i)
            moves[i] = loc - i;
        else
            moves[i] = n - i + loc;
    }
    mp.clear();
    for (int i = 1; i <= n; i++) {
        mp[moves[i]]++;
    }
    int ans = 0;
    for (auto x : mp) {
        ans = max(ans, x.second);
    }
    cout << ans << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
