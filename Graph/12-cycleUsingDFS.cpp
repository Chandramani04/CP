#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // detect a cycle in a undirected graph using a dfs

    vector<int> vis(n + 1, 0);
    function<bool(int, int)> dfs = [&](int node, int parent) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, node)) {
                    return true;
                }
            } else if (it != parent) {
                return true;
            }
        }
        return false;
    };

    // if a graph have multiple components then we need to run a loop
    // to check for each component
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) {
                cout << i << endl;
                cout << "Cycle detected\n";
                return;
            }
        }
    }


    // below code also works but it is not efficient

    
    // vector<int> vis(n + 1, 0);
    // int cycle = 1;
    // function<void(int, int)> dfs = [&](int node, int parent) {
    //     if (node != parent and node == 1) {
    //         cout << node << endl;
    //         cout << parent << endl;
    //         cout << "Cycle detected\n";
    //         return;
    //     }
    //     for (auto it : adj[node]) {
    //         if (it != parent and !vis[it]) {
    //             vis[it] = 1;
    //             dfs(it, node);
    //             cycle++;
    //         }
    //     }
    // };
    // dfs(adj[1][0], 1);
    // cout << cycle << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
