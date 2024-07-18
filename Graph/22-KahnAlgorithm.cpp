// kahn's algo is topo sort using bfs

#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> inDegree(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    // for(auto i : adj) {
    //     for(auto j : i) {
    //         inDegree[j]++;
    //     }
    // }

    // inDegree stores the number of incoming edges to a node

    queue<int> q;
    // step 1 : push all the nodes with inDegree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> store;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        store.push_back(node);

        // removes all the edges that are connected with this node

        for (auto it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it);
            }
        }
    }
    for (auto i : store) {
        cout << i << " ";  // 4 5 0 2 3 1
    }
    cout << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
