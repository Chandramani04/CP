#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
int numberOfPairs(vector<vector<int>>& points) {
    vector<vector<int>> v = points;
    sort(v.begin(), v.end());
    int cnt = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        int x = v[i][0], y = v[i][1];
        // count from i + 1 till n , how many points are such that
        // no other point comes in between rectangle formed by (x,y) and (new x,new y)
        for (int j = i + 1; j < n; j++) {
            int new_x = v[j][0], new_y = v[j][1];
            bool ok = true;
            for (int k = 0; k < n; i++) {
                int l = v[k][0], r = v[k][1];
                if ((l > x and l < new_x) and (r > y and r < new_y)) {
                    ok = false;
                    break;
                }
            }
            if (ok) cnt++;
        }
    }
    return cnt;
}
long long maximumSubarraySum(vector<int>& nums, int k) {
    long long n = nums.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    // -1 2 4 8 13
    long long ans = INT_MIN;
    bool ok = false;
    set<long long> s;
    map<long long, vector<long long>> mp;
    for (int i = 0; i < n; i++) {
        // check if v[i]-k is present in the set
        long long target = nums[i] - k;
        long long neg = nums[i] + k;
        if (s.count(target)) {
            ok = true;
            vector<long long> v = mp[target];
            for (auto x : v) {
                ans = max(ans, pre[i + 1] - pre[x]);
            }
        }
        if (s.count(neg)) {
            ok = true;
            vector<long long> v = mp[neg];
            for (auto x : v) {
                ans = max(ans, pre[i + 1] - pre[x]);
            }
        }
        // if (s.count(target)) {
        //     ok = true;
        //     ans = max(ans, pre[i + 1] - pre[mp[target]]);
        // }
        // if (s.count(neg)) {
        //     ok = true;
        //     ans = max(ans, pre[i + 1] - pre[mp[neg]]);
        // }
        s.insert(nums[i]);
        mp[nums[i]].push_back(i);
        // mp[nums[i]] = i;
    }
    if (ok) {
        return ans;
    } else {
        return 0ll;
    }
}
void solve() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << maximumSubarraySum(v, k) << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
