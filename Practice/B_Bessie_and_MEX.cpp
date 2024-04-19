#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
// void solve() {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++) cin >> a[i];
//     int mex[n + 1];
//     mex[0] = 0;
//     for (int i = 0; i < n; i++) {
//         mex[i + 1] = mex[i] + max(0LL, a[i]);
//     }
//     for (int i = 0; i < n; i++) {
//         cout << mex[i + 1] - a[i] << " ";
//     }
//     cout << endl;
// }

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mex = 0;
    // int p[n+1];
    vector<int> p(n + 1);
    vector<bool>vis(n+1);
    // auto MEX = [&](int mex) {
    //     while (vis[mex]) mex++;
    //     return mex;
    // };
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            // pi = mex(pi-1);
            p[i] = mex;
            vis[p[i]] = 1;

        } else {
            // pi = mex(pi-1)-a[i]
            p[i] = mex - a[i];
            vis[p[i]] = true;
        }
        while(vis[mex])mex++;
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
