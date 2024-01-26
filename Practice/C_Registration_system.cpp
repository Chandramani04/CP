#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
map<string, int> mp;
void solve() {
    string s;
    cin >> s;
    if (mp[s] == 0) {
        cout << "OK" << endl;
        mp[s]++;
    } else {
        cout << s << mp[s] << endl;
        mp[s]++;
    }
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
