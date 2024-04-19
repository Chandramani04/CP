#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
int findXOR(int n) {
    int mod = n % 4;
    if (mod == 0) return n;
    if (mod == 1) return 1;
    if (mod == 2) return n + 1;
    return 0;
}
void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
        cout << b << endl;
        return;
    }
    int ans = findXOR(a - 1) ^ findXOR(b);
    cout << ans << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
