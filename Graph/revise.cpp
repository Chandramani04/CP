#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
vector<vector<int>> adj;
vector<int> vis(100001, -1);

void dfs() {
    // need -> vis array , starting node
    int startingnode;
    function<void(int)> rec = [&](int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[node] == -1) {
                rec(it);
            }
        }
    };
}
void bfs() {
    // need -> queue , vis array , starting node
    queue<int> q;
    int node;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[node] == -1) {
                q.push(node);
            }
        }
    }
}
void detectCycleByDFS() {
    int start;
    function<void(int)> rec = [&](int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (it != node) {  // all edges except parent edge
                if (vis[node] == -1) {
                    rec(node);
                } else if (vis[node] == 1) {
                    // previously marked 1 in the same path =>cycel detected
                    cout << "CYcle " << endl;
                    return;
                }
            }
        }
    };
}

void detectCycleByBFS() {
    int start;
    function<bool(int)> rec = [&](int node) {
        queue<int> q;
        q.push(node);
        while (q.empty()) {
            int t = q.front();
            q.pop();
            vis[t] = 1;
            for (auto it : adj[t]) {
                if (vis[it] == -1) {
                    q.push(it);
                } else if (it != t and vis[it] == 1) {
                    return false;
                }
            }
        }

        return true;
    };
}
void bipartiteDFS() {
    // two adjacent nodes should not have same color
    vector<int> color(100001, -1);
    function<void(int, int)> rec = [&](int curNode, int curColor) {
        vis[curNode] = 1;
        color[curNode] = curColor;
        for (auto it : adj[curNode]) {
            if (vis[it] == -1) {
                rec(it, curColor ^ 1);  // fill with opposite color
            } else if (vis[it] == 1 and color[it] == curColor) {
                cout << "NOt bipartite" << endl;
                return;
            }
        }
    };
    cout << "else bipartite" << endl;
}
void bipartiteBFS() {
    queue<pair<int, int>> q;
    vector<int> colour(10001, -1);
    int start;
    q.push({start, 0});
    while (!q.empty()) {
        int node = q.front().first, col = q.front().second;
        q.pop();
        vis[node] = 1;
        colour[node] = col;
        for (auto it : adj[node]) {
            if (vis[it] == -1) {
                q.push({it, col ^ 1});
            } else if (vis[it] == 1 and colour[it] == col) {
                cout << "NOt bipartite" << endl;
                return;
            }
        }
    }
}
void cycleInDirectedGraph() {
    vector<int> pathVis(100000, 0);
    function<bool(int)> rec = [&](int node) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[it] == -1 and rec(it) == true) {
                // it not visited but a path from it is visited and cycle is present
                return true;
            } else if (pathVis[it] == 1) {
                // it was previously visited in current path -> cycle present
                return true;
            }
        }
        // we didn't found any cycle
        pathVis[node] = 0;  // no cycle present in current path

        return false;  // no cycle in graph
    };
}

void topoUsingDFS() {
    /*
    only applied for DAG
    topo sort -> if u->v  then u comes before v in topological ordering
    */
    vector<int> topo;
    function<void(int)> rec = [&](int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[node] == -1) rec(node);
        }
        topo.push_back(node);
    };
    reverse(topo.begin(), topo.end());
    // to check valid DAG or not
    // if topo.size() == #nodes -> valid DAG else not
}

void KahnAlgo() {
    // toposort using bfs
    /*
        since we store a node in topo sort with dfs when all dfs for all it's adjacents nodes are completed .
        similarily we push elements in queue when it has indeggree = 0
    */
    queue<int> q;
    int start;
    vector<int> indegree;
    int n;  // #total nodes
    // u -> v edge then indegree[v]++
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> kahns;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        kahns.push_back(node);
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    // print kahns vector
}
void shortedPathfromSingleSourcetoAllVertices() {
    /*
        topo sort
        relax edge
    */
    vector<int> topo;
    function<void(int)> dfs = [&](int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[it] == -1) {
                dfs(it);
            }
        }
        topo.push_back(node);
    };
    reverse(topo.begin(), topo.end());

    vector<int> dist(10000, 1e9);  // set infinity

    int sourceNode;
    dist[sourceNode] = 0;

    for (int i = 0; i < topo.size(); i++) {
        for (auto it : adj[topo[i]]) {
            // u -w-> v

            int u = topo[i];
            int v;  // it.first
            int w;  // it.second weighted graph

            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    // print distance array
}

// void dijkstra() {
//     /*
//         shortest path from a single source to all vertices
//     */
//     // bfs using priority queue
//     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;
//     int src = 0;
//     vector<int> dist(1000000, 1e9);

//     p.push({src, 0});
//     while (!p.empty()) {
//         int node = p.top()[0], dis = p.top()[1];
//         p.pop();
//         for (auto it : adj[node]) {
//             int v = it[0], w = it[1];
//             if (dis + w < dist[v]) {
//                 dist[v] = dis + w;
//                 p.push({v, dist[v]});
//             }
//         }
//     }
// }

void solve() {
}
signed main() {
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        solve();
}
