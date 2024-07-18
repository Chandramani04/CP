/*
Bridge : any edge which on removing , graph will get broken into two or more components

to find bridge :
time in array : time when we reach the node
low time array : lowest time node which can be reached from the current node except the parent node

*/
#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/
vector<vector<int>> criticalConnections(int n,
                                        vector<vector<int>>& connections) {
    // return all the bridges in the graph
    vector<int> adj[n];
    for (auto it : connections) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    // vector<int> low(n);
    // vector<int> time(n);
    int low[n];
    int time[n];
    // timer
    vector<vector<int>> ans;
    int timer = 1;

    function<void(int, int)> dfs = [&](int node, int parent) -> void {
        vis[node] = 1;
        low[node] = timer;
        time[node] = timer;
        timer++;

        for (auto it : adj[node]) {
            if (it != parent) {
                if (!vis[it]) {
                    dfs(it, node);
                    low[node] =
                        min(low[node],
                            low[it]);  // can we reach it with lesser time
                    // if current edge node -> it is a bridge
                    if (low[it] > time[node]) {
                        // minimum time to reach it from current node is
                        // greater than the time when we reach the current
                        // node
                        // therefore this edge is a bridge
                        ans.push_back({node, it});
                    }
                } else {
                    // it's already a visited node , therefore we just
                    // update the low time
                    low[node] = min(low[node], low[it]);
                }
            }
        }
    };

    dfs(0, -1);

    return ans;
}
void solve() {
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
