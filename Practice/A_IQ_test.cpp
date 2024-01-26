#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int even = 0, odd = 0;
    // even-odd, prime-not prime , all equal- 1 dif
    for (auto x : v) {
        if (x % 2 == 0)
            even++;
        else
            odd++;
    }
    if (even == 1) {
        for (int i = 0; i < n; i++) {
            if (v[i] % 2 == 0) {
                cout << i + 1 << endl;
                return;
            }
        }
    } else if (odd == 1) {
        for (int i = 0; i < n; i++) {
            if (v[i] % 2 == 1) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
    int np = 0, nnp = 0;
    for (auto x : v) {
        if (is_prime(x))
            np++;
        else
            nnp++;
    }
    if (np == 1) {
        for (int i = 0; i < n; i++) {
            if (is_prime(v[i])) {
                cout << i + 1 << endl;
                return;
            }
        }
    } else if (nnp == 1) {
        for (int i = 0; i < n; i++) {
            if (!is_prime(v[i])) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
    set<int> st(v.begin(), v.end());
    if (st.size() == 2) {
        // find the element which is differenet from  othere
        int f = *st.begin();
        int fcnt = count(v.begin(), v.end(), f);
        st.erase(f);
        int s = *st.begin();
        int scnt = count(v.begin(), v.end(), s);
        if (fcnt == 1) {
            for (int i = 0; i < n; i++) {
                if (v[i] == f) {
                    cout << i + 1 << endl;
                    return;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (v[i] == s) {
                    cout << i + 1 << endl;
                    return;
                }
            }
        }
    }
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
