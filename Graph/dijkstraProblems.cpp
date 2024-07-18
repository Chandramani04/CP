#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9 + 7;

/*-----------------------------------------------------------------*/
void solve() {
    cout << "hello world" << endl;
}
int shortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;

    // p.top = {x,y,dis}
    p.push({source.first, source.second, 0});
    dist[source.first][source.second] = 0;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!p.empty()) {
        auto cell = p.top();
        p.pop();
        int x = cell[0], y = cell[1], dis = cell[2];
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            // only jump if the new cell is valid
            if (nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == 1) {
                if (dis + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dis + 1;
                    p.push({nx, ny, dis + 1});
                }
            }
        }
    }
    if (dist[destination.first][destination.second] == INT_MAX) return -1;
    return dist[destination.first][destination.second];
}

int minimumEffortPath(vector<vector<int>>& grid) {  // weighted graph
    int n = grid.size(), m = grid[0].size();
    if (n == 1 and m == 1) return 0;

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;
    p.push({0, 0, 0});  //{dis , x, y }

    while (!p.empty()) {
        auto cell = p.top();
        p.pop();
        int dis = cell[0], x = cell[1], y = cell[2];
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
                int cost = abs(grid[nx][ny] - grid[x][y]);
                // if we go with this path
                int newEffort = max(dis, cost);
                if (newEffort < dist[nx][ny]) {
                    dist[nx][ny] = newEffort;
                    p.push({newEffort, nx, ny});
                }
            }
        }
    }
    return dist[n - 1][m - 1];
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int, int>> adj[n];
    for (auto f : flights) {
        adj[f[0]].push_back({f[1], f[2]});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;

    p.push({0, src, 0});  //{stops,node,costs}

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!p.empty()) {
        auto cell = p.top();
        p.pop();
        int stops = cell[0], node = cell[1], cost = cell[2];
        if (stops > k) {
            continue;
        }
        for (auto i : adj[node]) {
            int v = i.first, w = i.second;
            if (cost + w < dist[v] and stops <= k) {
                dist[v] = cost + w;
                p.push({stops + 1, v, cost + w});
            }
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int networkDelayTime(vector<vector<int>>& times, int n, int src) {
    vector<pair<int, int>> adj[n + 1];
    for (auto i : times) {
        adj[i[0]].push_back({i[1], i[2]});
    }
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, src});
    dist[src] = 0;

    while (!p.empty()) {
        int node = p.top().second;
        int dis = p.top().first;
        p.pop();
        for (auto it : adj[node]) {
            int v = it.first, w = it.second;
            if (dis + w < dist[v]) {
                dist[v] = dis + w;
                p.push({dis + w, v});
            }
        }
    }
    int ans = *max_element(dist.begin() + 1, dist.end());
    return ans == INT_MAX ? -1 : ans;
}

int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> adj[n];
    for (auto i : roads) {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    int src = 0, dst = n - 1;
    int count = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    vector<int> dist(n, INT_MAX);
    vector<int> ways(n, 0);
    ways[0] = 1;
    p.push({0, src});
    while (!p.empty()) {
        int node = p.top().second, time = p.top().first;
        p.pop();
        for (auto it : adj[node]) {
            int v = it.first, w = it.second;
            if (time + w < dist[v]) {
                dist[v] = time + w;
                ways[v] = ways[node];
                p.push({dist[v], v});
            } else if (time + w == dist[v]) {
                ways[v] += ways[node];
                ways[v] %= mod;
            }
        }
    }
    return ways[n - 1];

    // count the number of paths from src to dst with minimum distance = dist[dst]

    // return dist[dst];
}

int minimumMultiplications(vector<int>& arr, int start, int end) {
    vector<long long> dist(1e5 + 10, 1e18);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> p;
    p.push({0, start});
    dist[start] = 0;
    while (!p.empty()) {
        long long num = p.top().second, dis = p.top().first;
        p.pop();
        for (auto it : arr) {
            long long no = num * it;
            no %= (long long)100000;
            if (dis + 1 < dist[no]) {
                dist[no] = dis + 1;
                p.push({dis + 1, no});
            }
        }
    }
    return dist[end] == 1e18 ? -1 : dist[end];
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
