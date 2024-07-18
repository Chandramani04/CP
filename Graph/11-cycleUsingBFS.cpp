// detect a cycle in a undirected graph using a bfs
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
    function<void(int)> bfs = [&](int node) {
        vector<int> vis(n + 1, 0);
        queue<pair<int, int>> q;
        vis[node] = 1;
        for (auto it : adj[node]) {
            q.push({it, node});
            vis[it] = 1;
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            // x = current node, y = from where we came to x
            q.pop();
            for (auto it : adj[x]) {
                if (it != y) {
                    if (vis[it]) {
                        cout << it << endl;
                        cout << "Cycle detected\n";
                        return;
                    } else {
                        vis[it] = 1;
                        q.push({it, x});
                    }
                }
            }
        }
    };
    bfs(1);
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
