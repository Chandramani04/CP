/*
Floyd Warshall Algorithm :
It is multi source shortest path algorithm.
It is used to find the shortest path between all pairs of nodes in a graph.

It works for both -ve edges and -ve cycles.

works for directed graphs
if undirected graph given, convert it into directed graph


CONCEPT : we will maintain a 2D array dist[][] where dist[i][j] will store the shortest distance between i and j

i -> k -> j

say we are at node i , we will try to go to node j through node k and check if the distance is minimum or not
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])


we will go VIA each node (i.e. for k = all nodes ) and update the dist[][] array

*/

#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (auto it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        dist[u][v] = wt;
        dist[v][u] = wt;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j and dist[i][j] <= distanceThreshold) {
                v[i]++;
            }
        }
    }
    int ct = *min_element(v.begin(), v.end());
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == ct) {
            return i;
        }
    }
    return -1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;  // distance from i to i = 0
    }
    for (auto it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        dist[u][v] = wt;  // since it's directed weighted graph , dist[u][v] = edge weight  , can be -ve
    }

    for (int k = 1; k <= n; k++) {          // k is the intermediate node
        for (int i = 1; i <= n; i++) {      // i is the source node
            for (int j = 1; j <= n; j++) {  // j is the destination node
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // print the dist matrix
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
