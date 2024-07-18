#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

// connected components are the subgraphs in a graph where each node is connected to each other 
// and there is no edge between the nodes of different connected components
// we can find the number of connected components in a graph using DFS
// we will start from a node and visit all the nodes connected to it and mark them as visited
// then we will move to the next node which is not visited and repeat the process
// the number of times we have to repeat the process is the number of connected components in the graph

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        for (auto i : adj[node]) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    };

    int connectedComponents = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            connectedComponents++;
        }
    }

    cout << connectedComponents << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
