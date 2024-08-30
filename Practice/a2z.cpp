#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> res;
    sort(nums.begin(), nums.end());
    set<int> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int req = -(nums[i] + nums[j]);
            if (st.count(req)) {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(req);
                sort(temp.begin(), temp.end());
                res.insert(temp);
            }
        }
        st.insert(nums[i]);
    }
    vector<vector<int>> ans;
    for (auto x : res) {
        ans.push_back(x);
    }
    return ans;
}
void solve() {
    // int n;
    // cin >> n;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
