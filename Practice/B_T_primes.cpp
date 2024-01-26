#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
set<int> ans;
void sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            ans.insert(i * i);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    if (ans.count(n)) {
        cout << "YES" << endl;
        return;
    } else {
        cout << "NO" << endl;
        return;
    }
}
signed main() {
    sieve(1000100);
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
