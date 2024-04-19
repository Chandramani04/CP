#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
// conclusions

// OR is distributive over AND
// a | (b & c) = (a | b) & (a | c)

// AND is distributive over OR
// a & (b | c) = (a & b) | (a & c)

int singleNumber(vector<int>& v) {
    vector<int> cnt(32, 0);
    for (int i = 0; i < v.size(); i++) {
        bitset<32> b(v[i]);
        for (int j = 0; j < 32; j++) {
            cnt[j] += b[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if (cnt[i] % 3 != 0) {
            ans += (1 << i);
        }
    }
    return ans;
}

void solve() {
    vector<int> nums = {0, 0, 0, 1, 1, 1, 99};
    cout << singleNumber(nums) << endl;
    bitset<5> b(16);
    cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << endl;
    cout << b << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
