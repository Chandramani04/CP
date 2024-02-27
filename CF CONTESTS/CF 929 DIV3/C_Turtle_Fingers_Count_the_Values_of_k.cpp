#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
int find_power(int number, int x) {
    int ans = 0;
    while ( number % x == 0 and number>0) {
        ans++;
        number /= x;
    }
    return ans;
}
void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    int ta = find_power(l, a);
    int tb = find_power(l, b);
    set<int> cnt;
    for (int la = 0; la <= ta; la++) {
        for (int lb = 0; lb <= tb; lb++) {
            int cn = pow(a, la) * pow(b, lb);
            if (l % cn == 0) {
                cnt.insert(l / cn);
            }
        }
    }
    cout << cnt.size() << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
