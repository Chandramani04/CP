#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/
// BFS : Breadth First Search
//  level wise traversal of a graph

// starting node is very important in BFS
// firstly we push the starting node in the queue (distance = 0)
// then we push all the nodes which are at a distance of 1 from the starting node
// then we push all the nodes which are at a distance of 2 from the starting node
// and so on

// distance for a node is the minimum number of edges from the starting node to that node

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // for undirected graph
    }

    // we have a input in form of adjacency list with n nodes and m edges
    vector<int> vis(n + 1, 0);
    int startingNode;
    cin >> startingNode;
    queue<int> q;
    q.push(startingNode);
    vis[startingNode] = 1;

    vector<int> bfs;

    while (!q.empty()) {  // while loop runs for all the nodes in the graph o(n)
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        // push all the nodes which are at a distance of 1 from the starting node or  push all the nodes which are neighbours of the current node
        for (auto it : adj[node]) { // for every node we are iterating over all the neighbours of that node i.e. all the degrees of that node
            if (!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    // time complexity = O(n + m) 
    // space complexity = O(n) + O(n) + O(n) = O(n)

    for (auto it : bfs) {
        cout << it << " ";
    }
    cout << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
