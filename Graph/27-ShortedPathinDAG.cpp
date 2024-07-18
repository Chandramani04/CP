// given a weighted directed acyclic graph, find the shortest path from a source to all other vertices in the graph.

#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    // step 1 : do a topo sort of the graph and store the order in a stack
    stack<int> st;
    vector<int> vis(n, 0);

    function<void(int)> dfs = [&](int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it.first]) {
                dfs(it.first);
            }
        }
        st.push(node);
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    // step 2 : initialize the distance array with infinity  and set the distance of the source node to 0
    vector<int> dist(n, 1e18);//INT_MAX for int 
    // let source node is 0 
    dist[0] = 0;


    // step 3 : iterate over the nodes in topological order and relax the edges (relaxing the edges means updating the distance if we find a shorter path)
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it:adj[node]){
            // u = node, v = it.first, w = it.second
            int v = it.first, w = it.second;
            // if distance of current node + weight of the edge < distance of the destination node, then update the distance of the destination node
            if(dist[node] + w < dist[v]){
                dist[v] = dist[node] + w;
            }
            // or dist[v] = min(dist[v], dist[u] + w);
        }
    }

    // step 4 : print the distance array
    for(int i=0; i<n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;

}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
