/*
Bellman Ford Algorithm : It is used to find the shortest path from a single source to all other vertices in a weighted graph.
It is a Dynamic Programming Algorithm.

//Only applicable for Directed Graphs
It can work with negative weight edges but not with negative weight cycle.(If there is a negative weight cycle, then the shortest path is not well defined)


if any path weight is -ve then graph has a negative weight cycle


//if undirected graph is given then we can convert it into directed graph by adding two edges for each edge

if n nodes given , we have to relax the edges n-1 times i.e.   (n-1)*(m) where m is the number of edges

because in worst case the shortest path can be n-1 edges long
0 ->  1 ->  2 ->  3 ->  4 -> 5   for n = 6 nodes we have n-1 edges in shortest path

how to detect a -ve cycle :

if after n-1 iterations , we can still relax the edges then there is a -ve cycle

relaxing the edges means updating the distance of the nodes from the source node

Time Complexity : O(n*m) where n is the number of nodes and m is the number of edges

*/

#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> dist(n, 1e18);
    int src;
    cin >> src;
    dist[src] = 0;

    for (int iteration = 1; iteration <= n - 1; iteration++) {
        // relaxing the edges
        for (auto it : edges) {
            int u = it[0], v = it[1], wt = it[2];  // wt can be -ve
            if (dist[u] != 1e18 and dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // checking for -ve cycle
    bool flag = 0;
    for (auto it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        if (dist[u] != 1e18 and dist[u] + wt < dist[v]) {
            cout << "Negative Cycle";
            flag = 1;
            break;
        }
    }
    if(!flag){
        for(int i = 0 ; i < n ; i++){
            cout << "Node " << i << " is at distance " << dist[i] << endl;
        }
    }
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
