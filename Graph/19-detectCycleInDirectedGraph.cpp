#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> nodeVis(n + 1, 0), pathVis(n + 1, 0);

    function<bool(int)> dfs = [&](int node) {
        pathVis[node] = 1;
        nodeVis[node] = 1;

        for (auto i : adj[node]) {
            if (!(nodeVis[i]) and dfs(i) == true) {
                return true;
            } else if (pathVis[i]) {  // we have already visited this node in the current path so cycle detected
                return true;
            }
        }
        // backtracking step
        pathVis[node] = 0;  // [IMP] This is important to reset the pathVis[node] to 0 after the dfs call is over
        // we didn't find any cycle from this path so we can reset all the pathVis[node] = 0 in this recursive depth of the dfs call
        return false;
    };

    for (int isCycleStartingFrom = 1; isCycleStartingFrom <= n; isCycleStartingFrom++) {
        if (!nodeVis[isCycleStartingFrom] and dfs(isCycleStartingFrom)) {
            // cout << "Cycle detected" << endl;
            
            return;
        }
    }
    cout << "No cycle detected" << endl;    
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
