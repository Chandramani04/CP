#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/
/*
    Concept of Dijkstra Algorithm :
    1. Dijkstra Algorithm is used to find the shortest path from a single source to all other vertices in a weighted graph.
    2. It is a Greedy Algorithm.

    Algorithm :
    //bfs using min heap priority queue

    Does not work for :
    1. Negative Weight Cycle
    2. Does not work for negative weight edges

*/

void UsingSet() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    set<pair<int, int>> st;
    vector<int> dist(n, INT_MAX);
    int src = 0;
    st.insert({src, 0});
    dist[src] = 0;
    while (!st.empty()) {
        auto it = *st.begin();
        st.erase(st.begin());
        int node = it.first, dis = it.second;
        for (auto i : adj[node]) {
            int v = i.first, w = i.second;
            if (dis + w < dist[v]) {
                auto f = st.find({v, dist[v]});// check if we have already reached there before
                if (f != st.end()) { // someone already reached there before and we are reaching there with less distance so remove previous one 
                    st.erase(f);
                }
                dist[v] = dis + w;
                st.insert({v, dist[v]});
            }
        }
    }
    // return dist;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n, INT_MAX);
    // creat a min heap

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    int src = 0;  // Source Node is 0

    p.push({src, 0});

    dist[src] = 0;

    while (!p.empty()) {
        // auto [node, dis] = p.top();
        int node = p.top().first, dis = p.top().second;  // dis = dist[node]
        p.pop();
        for (auto it : adj[node]) {
            int v = it.first, w = it.second;
            if (dis + w < dist[v]) {
                dist[v] = dis + w;
                p.push({v, dist[v]});
            }
        }
    }
    // return dist;

    //time complexity = O(ElogV) //why ? because we are using min heap and we are visiting each edge once and we are visiting each vertex once so total time complexity = O(ElogV)
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
