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
    if (is_sorted(v.begin(), v.end())) {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    int revcnt = 0;
    vector<int> rev;
    vector<vector<int>> cmd;
    for (int i = 0; i < n;) {
        if (i < n - 1 and v[i] > v[i + 1]) {
            rev.push_back(v[i]);
            i++;
        } else {
            if (rev.size()) {
                rev.push_back(v[i]);
                int next = -1;
                if (i < n - 1) next = v[i + 1];
                cmd.push_back(rev);
                rev.clear();
            }
            i++;
        }
    }

    // for (auto x : cmd) {
    //     for (auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    if (cmd.size() > 1) {
        cout << "no" << endl;
        return;
    }
    vector<int> ans = cmd[0];
    // for(auto x:ans){
    //     cout<<x<< " ";
    // }
    // cout<<endl;
    int f = ans[0], la = ans.back();
    int l = find(v.begin(), v.end(), f) - v.begin();
    int r = find(v.begin(), v.end(), la) - v.begin();

    bool left = true, right = true;
    if (r + 1 < n and v[r + 1] < ans[0]) left = false;
    if (l > 0 and v[l - 1] > ans.back()) right = false;

    if (left and right) {
        cout << "yes" << endl;
        cout << l + 1 << " " << r + 1 << endl;
        return;
    } else {
        cout << "no" << endl;
    }
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
