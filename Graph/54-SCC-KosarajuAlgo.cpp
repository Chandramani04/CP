/*
SCC : strongly connected components
a SCC is a subgraph in which every node is reachable from every other node in the subgraph

only works for directed graph

Kosaraju's Algorithm:

Intution : reverse the edge direction , now it doesn't affect the SCC's but it helps to find the SCC's  because after reversion we can't go outside the SCC


1.sort all the edges according to finishing time(finish time also found by dfs)
2.reverse the graph
3.do a dfs

*/

#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    // only works for directed graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(n + 1, 0);
    stack<int> order;
    function<void(int)> dfs = [&](int node) -> void {
        vis[node] = true;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it);
            }
        }
        order.push(node);
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    // reverse the graph
    vector<int> adjRev[n + 1];
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            adjRev[it].push_back(i);
        }
    }

    int scc = 0;  // number of strongly connected components
    vis = vector<int>(n + 1, 0);

    function<void(int)> dfs2 = [&](int node) -> void {
        vis[node] = true;
        // cout << node << " ";
        for (auto it : adjRev[node]) {
            if (!vis[it]) {
                dfs2(it);
            }
        }
    };

    while (!order.empty()) {
        int node = order.top();
        order.pop();
        if (!vis[node]) {
            dfs2(node);
            scc++;
        }
    }
    cout << scc << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
