/*
    Kruskal :
1.sort all the edges according to edge weights
2.create a DSU
 if u and v belongs to same component then skip that edge
 else add that edge to MST
*/
#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/

class DSU {
   private:
    vector<int> rank;
    vector<int> parent;  // stores ultimate parent of a node
    vector<int> size;    // store the size of the component(#allnodes)

   public:
    // constructor
    DSU(int n) {
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // initially parent of all nodes is itself
            rank[i] = 0;    // initially rank of all nodes is 0
            size[i] = 1;    // initially size of all nodes is 1
        }
    }
    // path compression
    int ultimateParent(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = ultimateParent(parent[x]);
    }

    // union : adding an edge bw two nodes by rank
    // connect smaller to larger
    void unionByrank(int u, int v) {
        int ulp_u = ultimateParent(u);
        int ulp_v = ultimateParent(v);
        if (ulp_u == ulp_v) {
            return;  // they are already in same component
        }
        if (rank[ulp_u] < rank[ulp_v]) {
            // connect u to v
            parent[ulp_u] = ulp_v;  // parent of u is v now
        } else if (rank[ulp_u] > rank[ulp_v]) {
            // connect v to u
            parent[ulp_v] = ulp_u;  // parent of v is u now
        } else {
            // connect v to u or u to v and increase rank of u
            parent[ulp_v] = ulp_u;  // parent of v is u now
            rank[ulp_u]++;          // increase rank of u
        }
    }

    // Union by size :adding two components by size

    void unionBySize(int u, int v) {
        int ulp_u = ultimateParent(u);
        int ulp_v = ultimateParent(v);
        if (ulp_u == ulp_v) return;       // they are already in same component
        if (size[ulp_u] < size[ulp_v]) {  // add component of u to component of v
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    bool isSameComponent(int u, int v) {
        return ultimateParent(u) == ultimateParent(v);
    }
};

int removeStones(vector<vector<int>>& stones) {
    // ans = number of stones - number of connected components
    int n = stones.size();  // number of total stones

    int maxrow = 0, maxcol = 0;
    for (auto it : stones) {
        maxrow = max(maxrow, it[0]);
        maxcol = max(maxcol, it[1]);
    }

    /*
    row denoted with 0 to maxrow
    col denotes with maxrow+1 to maxrow+maxcol
    */
    DSU ds(maxrow + maxcol + 2);
    map<int, int> mp;  // mp stores which row and col are connected
    for (auto it : stones) {
        ds.unionBySize(it[0], it[1] + maxrow + 1);
        mp[it[0]] = 1;
        mp[it[1]] = it[1] + maxrow + 1;
    }

    int cnt = 0;
    for (auto it : mp) {
        if (ds.ultimateParent(it.first) == it.first) {
            cnt++;
        }
    }
    return n - cnt;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    // in final ans : n nodes , n -1 edges
    // MST Problem
    DSU ds(n);
    // how to find extra edges
    int extraEdges = 0;  // extra edges means even if we remove these edges , component will be connected
    for (auto connection : connections) {
        int u = connection[0], v = connection[1];

        if (ds.ultimateParent(u) == ds.ultimateParent(v)) {
            extraEdges++;
        } else {
            ds.unionBySize(u, v);
        }
    }
    // how to find number of connected components
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (ds.ultimateParent(i) == i) {
            components++;
        }
    }

    if (extraEdges >= components - 1) {
        return components - 1;
    } else {
        return -1;
    }
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

    // sort edges according to their weight
    vector<pair<int, pair<int, int>>> edges;
    for (int node = 0; node < n; node++) {
        auto vec = adj[node];
        for (auto it : vec) {
            int w = it.second, v = it.first, u = node;
            edges.push_back({w, {u, v}});
        }
    }

    sort(edges.begin(), edges.end());

    vector<pair<int, int>> mst;
    int mstWeight = 0;
    DSU ds(n);
    for (auto edge : edges) {
        int w = edge.first, u = edge.second.first, v = edge.second.second;
        if (ds.isSameComponent(u, v) == false) {
            ds.unionBySize(u, v);
            mst.push_back({u, v});
            mstWeight += w;
        }
    }
    cout << mstWeight << endl;
    for (auto it : mst) {
        cout << it.first << " " << it.second << endl;
    }
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
