#include "bits/stdc++.h";
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
/*-----------------------------------------------------------------*/
//find total number of shortest paths from 1 to n
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> totalWays(n + 1, 0), minDist(n + 1, 1e15);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;  //{minDist,curNode}

    p.push({0, 1});
    totalWays[1] = 1;
    minDist[1] = 0;

    while (!p.empty()) {
        auto t = p.top();
        p.pop();
        int d = t[0], node = t[1];
        for (auto it : adj[node]) {
            // min dist to reach it
            int dist_it = minDist[it];
            if (d + 1 < dist_it) {
                minDist[it] = d + 1;
                totalWays[it] = totalWays[node];
                p.push({d + 1, it});
            } else if (d + 1 == dist_it) {
                // same shortest path
                totalWays[it] = (totalWays[it] % MOD + totalWays[node] % MOD) % MOD;
            }
        }
    }

    cout << totalWays[n] << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}




