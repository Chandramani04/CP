#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/
/*
adjacency_list = {
    1: [2, 3, 7],
    2: [4, 7],
    3: [5, 7],
    4: [6],
    5: [6],
    7: [6],
    6: []
}
// n = 7 , m = 10
*/
void solve() {
    int n, m;
    cin >> n >> m;  // n = number of nodes, m = number of edges
    vector<int> adj[n + 1];
    // for (int i = 0; i < n; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    adj[1] = {2, 3, 7};
    adj[2] = {4, 7};
    adj[3] = {5, 7};
    adj[4] = {6};
    adj[5] = {6};
    adj[7] = {6};
    adj[6] = {};
    int startingNode = 1;
    // cin >> startingNode;

    vector<int> storedfs;
    storedfs.push_back(startingNode);
    vector<bool> visited(n + 1, false);
    visited[startingNode] = true;
    function<void(int)> dfs = [&](int node) {
        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = true;
                storedfs.push_back(it);
                dfs(it);
            }
        }
    };

    dfs(startingNode);
    for (auto i : storedfs) {
        cout << i << " ";
    }

    // space complexity = O(n)
    // time complexity = O(n + 2*m)
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
