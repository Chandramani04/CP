#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(45, 0);
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        bitset<45> b(x);
        for (int i = 0; i < 45; i++) {
            if (b[i]) {
                cnt[i]++;
            }
        }
    }
    int num = 0;
    for (int i = (int)cnt.size() - 1; i >= 0; i--) {
        int set = cnt[i];
        int unset = n - set;
        int temp = num | (1LL << i);
        if (temp > k) {
            continue;
        }
        if (unset > set) {
            num = temp;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (num ^ arr[i]);
    }
    cout << ans << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
