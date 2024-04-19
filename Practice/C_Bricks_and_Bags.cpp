#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int ans = a[n - 1] - a[0];
    for (int i = 0; i < n - 1; i++) {
        ans = std::max({ans, a[i + 1] + a[n - 1] - 2 * a[i], 2 * a[i + 1] - a[i] - a[0]});
    }
    std::cout << ans << "\n";
}
signed main(){
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
