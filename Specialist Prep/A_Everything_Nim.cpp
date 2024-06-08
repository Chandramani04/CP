#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> st;
    for (auto &x : a) cin >> x, st.insert(x);

    int t = 0;
    int p = 1;
    while (true && st.size()) {
        if (st.count(p)) {
            st.erase(p);
            p++;
            t ^= 1;
            continue;
        }

        if (t == 0) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
        return;
    }

    if (t == 0)
        cout << "Bob\n";
    else
        cout << "Alice\n";
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}