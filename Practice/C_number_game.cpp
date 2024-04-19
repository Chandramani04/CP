#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
bool ispoweroftwo(int n) {
    return (n && !(n & (n - 1)));
}
bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    if (n == 1 or (n > 2 and ispoweroftwo(n)) or (n % 2 == 0 and (n / 2 > 2 and is_prime(n / 2)))) {
        cout << "FastestFinger" << endl;
    } else {
        cout << "Ashishgup" << endl;
    }
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
