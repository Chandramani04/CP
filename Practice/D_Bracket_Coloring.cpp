#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            cnt--;
        }
    }
    if (cnt != 0) {
        cout << -1 << endl;
        return;
    }
    auto check_single = [&](string temp) {
        // if check single is true , no need to reverse , only one color is needed
        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i] == '(') {
                ct++;
            } else {
                ct--;
            }
            if (ct < 0) {
                return false;
            }
        }
        return true;
    };
    auto print_single = [&]() {
        string temp = s;
        bool ok = false;
        if (check_single(temp)) {
            ok = true;
        }
        reverse(temp.begin(), temp.end());
        if (check_single(temp)) {
            ok = true;
        }
        if (ok) {
            cout << 1 << endl;
            for (int i = 0; i < n; i++) {
                cout << 1 << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    };

    if (print_single()) return;

    auto print_double = [&]() {
        int ct = 0, cur = 0;
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                cur++;
            else
                cur--;
            if (cur < 0 && s[i] == ')') {
                ct++;
                ans[i] = 2;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(' && ct) {
                ct--;
                ans[i] = 2;
            }
        }
        cout << 2 << endl;
        for (auto &it : ans)
            cout << it << " ";
        cout << endl;
    };
    print_double();
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
