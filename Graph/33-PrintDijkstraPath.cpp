#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[n + 1];
    for (auto i : edges) {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);//parent stores from where we reached the node
    for (int i = 1; i <= n; i++) parent[i] = i;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    int src = 1, des = n;
    dist[src] = 0;
    p.push({src, 0});

    while (!p.empty()) {
        auto [node, dis] = p.top();
        p.pop();
        for (auto i : adj[node]) {
            int v = i.first, w = i.second;
            if (dis + w < dist[v]) {
                dist[v] = dis + w;
                parent[v] = node;
                p.push({v, dist[v]});
            }
        }
    }
    if (dist[des] == 1e9) return {-1};
    vector<int> path;
    int node = n;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    path.push_back(dist[n]);
    reverse(path.begin(), path.end());
    return path;
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src = 1, dest = n;

    vector<int> cache(n + 1, -1);      // to store the parent of each node
    vector<int> dist(n + 1, INT_MAX);  // to store the distance of each node from source
    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({src, 0});

    while (!s.empty()) {
        auto it = *s.begin();
        s.erase(s.begin());
        int node = it.first;
        for (auto i : adj[node]) {
            int v = i.first, w = i.second;
            if (dist[node] + w < dist[v]) {
                if (dist[v] != INT_MAX) {
                    s.erase(s.find({v, dist[v]}));
                }
                dist[v] = dist[node] + w;
                cache[v] = node;
                s.insert({v, dist[v]});
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        // return {-1};
    } else {
        vector<int> path;
        for (int i = dest; i != -1; i = cache[i]) {
            path.push_back(i);
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        // return path;
    }
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
