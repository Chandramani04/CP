#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void solve() {
    // DAG = Directed Acyclic Graph
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> vis(n, 0);
    stack<int> st;

    function<void(int)> dfs = [&](int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it);
            }
        }
        st.push(node);
    };

    // always start from 0
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    for (auto i : ans) {
        cout << i << " ";  // 5 4 2 3 1 0
    }
    cout << endl;
}

signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
