#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/
//detect cycle in directed graph using bfs 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Using BFS
    // if topo sort size = n  => Acyclic , otherwise cyclic

    // Kahn's algo -> vis + indegree
    vector<int> vis(n, 0);
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto nodes : adj[i]) {
            indegree[nodes]++;
        }
    }
    queue<int> q;
    vector<int> topo;

    // push all the nodes whose indegree is 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        topo.push_back(node);
        q.pop();
        // removes all the edges that are connected with this node
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    if (topo.size() == n) {
        cout << "Acyclic";
    } else {
        cout << "Cyclic";
    }
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
