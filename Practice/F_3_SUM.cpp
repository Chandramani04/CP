#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    set<int> st;
    map<int, int> mp;
    for (auto x : v) {
        int last = x % 10;
        st.insert(last);
        mp[last]++;
    }
    for (auto [x, y] : mp) {
        // cout << x << " " << y << endl;
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                int tsum = i + j + k;

                if (tsum % 10 == 3) {
                    // cout << i << " " << j << " " << k << endl;
                    map<int, int> temp = mp;
                    if (temp[i] > 0) {
                        temp[i]--;
                        if (temp[j] > 0) {
                            temp[j]--;
                            if (temp[k] > 0) {
                                cout << "YES" << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
