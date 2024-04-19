#include "bits/stdc++.h";
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    ll l, r;
    cin >> l >> r;
    int rs = log2(r) + 1;
    int ls = log2(l) + 1;
    // cout << "rs: " << rs << " ls: " << ls << " ";
    // if (rs > ls) {
    //     ll t = 0;
    //     for (int i = 0; i < rs - 1; i++) {
    //         t |= (1LL << i);
    //     }
    //     cout << t << endl;
    //     // cout << "t : " << t << endl;
    //     return;
    // }
    ll ans = l;
    bitset<64> bl(l);
    for (int i = 0; i < 64; i++) {
        if (bl[i] == 1) {
            continue;
        }
        ll temp = ans;
        temp += (1LL << i);
        if (temp > r) {
            break;
        } else {
            ans += (1LL << i);
        }
    }
    cout << ans << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
