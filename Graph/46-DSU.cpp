/*
DSU = Disjoint Set Union
It is used to find the connected components in a graph.
It is used for dynamic graph.(Graph whose edges are added or removed in real time)
after any step, if we try to figure out whether two arbitrary nodes u and v belong to the same component or not, Disjoint Set will be able to answer this query in constant time.

Use of DSU :
1.to find parent of a node
2.Union(adding an edge bw two nodes)

Rank : distance between furthest leaf node and root node of a tree/component

Steps :
1.find ultimate parent of u and v
find rank of their ultimate parent
connect smaller rank to larger rank

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

void solve() {
    // n = number of nodes
    int n;
    cin >> n;

    DSU ds(n);  // creating object of DSU class with n nodes

    // connecting edges bewteen u to v
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.isSameComponent(3, 7)) {
        cout << "3 and 7 are in same component" << endl;
    } else
        cout << "NO" << endl;

    // print NO because 3 and 7 are not in same component

    ds.unionBySize(3, 7);
    if (ds.isSameComponent(3, 7)) {
        cout << "3 and 7 are in same component" << endl;
    } else
        cout << "NO" << endl;
    // print YES because 3 and 7 are in same component
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
