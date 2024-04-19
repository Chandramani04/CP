#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
int fx(int n) {
    return floor(log10(n) + 1);
}
void solve() {
    int n;
    cin >> n;
    priority_queue<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push(x);
    }
    int cnt = 0;
    while (!a.empty() and !b.empty()) {
        int x = a.top(), y = b.top();
        if (x == y) {
            a.pop();
            b.pop();
        } else if (x > y) {
            int t = fx(x);
            cnt++;
            a.pop();
            a.push(t);
        } else {
            int t = fx(y);
            cnt++;
            b.pop();
            b.push(t);
        }
    }
    cout << cnt << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
