#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void inputByAdjacencyMatrix() {
    // input of a graph
    int n, m;
    cin >> n >> m;  // n -> number of nodes, m -> number of edges

    // adjacency matrix
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // edge from u to v
        adj[u][v] = 1; // = weight of the edge if it is a weighted graph
        adj[v][u] = 1;  // for undirected graph
    }
    // if adj[u][v] = 1 then there is an edge from u to v
    // space complexity: O(n^2)
}

void inputByAdjacencyList() {
    // input of a graph
    int n, m;
    cin >> n >> m;  // n -> number of nodes, m -> number of edges

    // adjacency list
    vector<vector<int>> adj(n + 1); // we store the nodes which are connected to the current node
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // edge from u to v
        adj[u].push_back(v);
        adj[v].push_back(u);  // for undirected graph
    }
    // if there is an edge from u to v then adj[u] will contain v
    // space complexity: O(n + m)
}

void solve() {
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
