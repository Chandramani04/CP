#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, -1);

    // when a graph is disconnected then we need to run a loop
    // we need to color each component independently

    function<bool(int, int)> bfs = [&](int node, int color) {
        queue<pair<int, int>> q;
        q.push({node, 0});
        while (!q.empty()) {
            int nd = q.front().first, c = q.front().second;
            q.pop();
            if (vis[nd] == -1) {
                vis[nd] = c;
                for (auto it : graph[nd]) {
                    if (vis[it] == -1) {
                        q.push({it, c ^ 1});
                    } else if (vis[it] == c) {
                        return false;
                    }
                }
            }
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) {
            if (!bfs(i, 0)) {
                return false;
            }
        }
    }
    return true;
}

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
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (vis[it] == -1) {
                vis[it] = 1 - vis[node];
                q.push(it);
            }
            if (vis[it] == vis[node]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
