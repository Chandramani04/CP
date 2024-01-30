#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
int cnt(int a, int b, int r) {
    int x = 0;
    for (int i = 30; i >= 0; --i) {
        if (((a >> i) & 1) != ((b >> i) & 1)) {
            if ((x | (1 << i)) <= r) {
                x |= (1 << i);
            } else {
                break;
            }
        } else if ((x | ((a >> i) & 1) << i) <= r) {
            x |= ((a >> i) & 1) << i;
        }
    }
    return x;
}
void solve() {
    int a, b, r;
    cin >> a >> b >> r;
    cout << cnt(a, b, r) << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
