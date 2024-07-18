/*
MST : Minimum Spanning Tree
a tree with n vertex and n-1 edges with minimum total edge weight   and all nodes are reachable from any node to any other node
prism algorithm is used to find MST and MST total weight
*/
/*
Prism Algorithm : a greedy algorithm to find MST

for every node we go to a adjacent node with minimum weight edge
time complexity = O(ElogE) , space complexity = O(E)

required data structures :
vis array & priority queue(min heap)
*/
#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/


void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    // undirected weighted graph given as input  , we have to make MST  of it
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;  //{weight,node,parent}
    p.push({0, 0, -1});                                                        // weight = 0 , node = 0 , parent = -1
    vector<int> vis(n, 0);
    vector<pair<int, int>> mst;  // to store the MST
    int mstWt = 0;               // to store the total weight of MST

    while (!p.empty()) {
        auto x = p.top();
        p.pop();
        int curNode = x[1], curWt = x[0], parent = x[2];
        vis[curNode] = 1;
        if (parent != -1) {
            mst.push_back({parent, curNode});
            mstWt += curWt;
        }
        for (auto it : adj[curNode]) {
            int v = it.first, w = it.second;
            if (!vis[v]) {
                p.push({w, v, curNode});
            }
        }
    }
    cout << mstWt << endl;
    for (auto it : mst) {
        cout << it.first << " " << it.second << endl;
    }

}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
