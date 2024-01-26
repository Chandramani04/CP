#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int normal_cost = n * a;
    int special_ride = (n) / m;
    int special_cost = b * special_ride;
    if (special_ride * m != n) {
        int extra = n - special_ride * m;
        special_cost += min(extra * a, b);
    }
    
    cout << min(special_cost, normal_cost);
}
signed main() {
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        solve();
}
