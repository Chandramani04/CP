/*
You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.*/
#include "bits/stdc++.h";
using namespace std;
#define int long long
/*-----------------------------------------------------------------*/
vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src) {
    // code here
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> dis(n, 1e9);
    dis[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (dis[node] + 1 < dis[it]) {
                dis[it] = 1 + dis[node];
                q.push(it);
            }
        }
    }

    // queue<pair<int,int>>q;   
    // q.push({src,0});
    // while(!q.empty()){
    //     int node = q.front().first , wt = q.front().second;
    //     q.pop();
    //     for(auto it:adj[node]){
    //         if(dis[it]>wt+1){
    //             dis[it] = wt + 1;
    //             q.push({it,dis[it]});
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++) {
        if (dis[i] == 1e9) dis[i] = -1;
    }
    return dis;
}
void solve(){
   
}
signed main(){
    int testcase = 1;
    while (testcase--)
        solve();
}
