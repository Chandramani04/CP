#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, -1);

    function<bool(int, int)> dfs = [&](int node, int color) {
        vis[node] = color;
        for (auto it : adj[node]) {
            if (vis[it] == -1) {
                return dfs(it, color ^ 1);
            }
            if (vis[it] == vis[node]) {
                return false;
            }
        }
        return true;
    };

    for (int i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            if (!dfs(i, 0)) {
                cout << "Not Bipartite\n";
                return;
            }
        }
    }
    cout << "Bipartite\n";
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
