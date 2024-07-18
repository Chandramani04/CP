#include <bits/stdc++.h>

#include <functional>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    // -1 condition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                bool ok = false;
                if (i > 0 and grid[i - 1][j] == 1) ok = true;
                if (i < n - 1 and grid[i + 1][j] == 1) ok = true;
                if (j > 0 and grid[i][j - 1] == 1) ok = true;
                if (j < m - 1 and grid[i][j + 1] == 1) ok = true;
                if (!ok) {
                    return -1;
                }
            }
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    if (q.empty()) {
        return -1;
    }

    int maxPossibleRotten = 0;
    int currentRotten = q.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 or grid[i][j] == 2) {
                maxPossibleRotten++;
            }
        }
    }
    int time = 0;
    while (currentRotten < maxPossibleRotten) {
        queue<pair<int, int>> nq;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            if (row > 0 and grid[row - 1][col] == 1 and vis[row - 1][col] == 0) {
                nq.push({row - 1, col});
                vis[row - 1][col] = 1;
            }
            if (row < n - 1 and grid[row + 1][col] == 1 and vis[row + 1][col] == 0) {
                nq.push({row + 1, col});
                vis[row + 1][col] = 1;
            }
            if (col > 0 and grid[row][col - 1] == 1 and vis[row][col - 1] == 0) {
                nq.push({row, col - 1});
                vis[row][col - 1] = 1;
            }
            if (col < m - 1 and grid[row][col + 1] == 1 and vis[row][col + 1] == 0) {
                nq.push({row, col + 1});
                vis[row][col + 1] = 1;
            }
        }
        if (nq.empty()) {
            return -1;
        }
        q = nq;
        currentRotten += q.size();
        time++;
    }
    return time;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size(), m = image[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int oldColor = image[sr][sc];
    function<void(int, int)> rec = [&](int row, int col) {
        if (row < 0 || col < 0 || row >= n || col >= m || image[row][col] != oldColor || vis[row][col] == 1) {
            return;
        }
        vis[row][col] = 1;
        image[row][col] = color;
        rec(row + 1, col);
        rec(row - 1, col);
        rec(row, col + 1);
        rec(row, col - 1);
    };
    rec(sr, sc);
    return image;
}
int numIslands(vector<vector<char>>& grid) {
    // find the number of connected components in a graph
    int n = grid.size(), m = grid[0].size();
    /*
        0
      0 1 0
        0
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                bool ok = false;
                if (i > 0 and grid[i - 1][j] == 1) ok = true;
                if (i < n - 1 and grid[i + 1][j] == 1) ok = true;
                if (j > 0 and grid[i][j - 1] == 1) ok = true;
                if (j < m - 1 and grid[i][j + 1] == 1) ok = true;
                if (!ok) {
                    return -1;
                }
            }
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    function<void(int, int)> rec = [&](int row, int col) {
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0' || vis[row][col] == 1) {
            return;
        }
        vis[row][col] = 1;
        rec(row + 1, col);
        rec(row - 1, col);
        rec(row, col + 1);
        rec(row, col - 1);
        rec(row + 1, col + 1);
        rec(row + 1, col - 1);
        rec(row - 1, col + 1);
        rec(row - 1, col - 1);
    };

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && vis[i][j] == 0) {
                rec(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}
vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                q.push({{i, j}, 0});
                dist[i][j] = 0;
            }
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    while (!q.empty()) {
        auto [p, d] = q.front();
        q.pop();
        int row = p.first, col = p.second;
        if (vis[row][col]) continue;
        vis[row][col] = 1;
        dist[row][col] = min(dist[row][col], d);
        if (row > 0 and !vis[row - 1][col]) {
            q.push({{row - 1, col}, d + 1});
        }
        if (row < n - 1 and !vis[row + 1][col]) {
            q.push({{row + 1, col}, d + 1});
        }
        if (col > 0 and !vis[row][col - 1]) {
            q.push({{row, col - 1}, d + 1});
        }
        if (col < m - 1 and !vis[row][col + 1]) {
            q.push({{row, col + 1}, d + 1});
        }
    }
    return dist;
}
void solve1(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    function<void(int, int)> dfs = [&](int row, int col) {
        if (row < 0 or col < 0 or row >= n or col >= m or grid[row][col] == 'X' or vis[row][col] == 1) {
            return;
        }
        vis[row][col] = 1;
        dfs(row + 1, col);
        dfs(row - 1, col);
        dfs(row, col + 1);
        dfs(row, col - 1);
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {  // boundary of the grid
                if (grid[i][j] == '0') {
                    // all the connected components which are connected to this cell will always be 0
                    if (!vis[i][j]) {
                        dfs(i, j);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'O' and vis[i][j] == 0) {
                grid[i][j] = 'X';
            }
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
    }
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        int deltaRow[] = {0, 0, 1, -1};
        int deltaCol[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];
            if (newRow >= 0 and newCol >= 0 and newRow < n and newCol < m and grid[newRow][newCol] == 1 and vis[newRow][newCol] == 0) {
                q.push({newRow, newCol});
                vis[newRow][newCol] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 and vis[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    set<vector<pair<int, int>>> islands;

    // auto dfs = [&](int row, int col, vector<pair<int, int>>& carry, int r0, int c0) {
    //     carry.push_back({row - r0, col - c0});
    //     vis[row][col] = 1;
    //     int deltaRow[] = {0, 0, 1, -1};
    //     int deltaCol[] = {1, -1, 0, 0};
    //     for (int i = 0; i < 4; i++) {
    //         int newRow = row + deltaRow[i];
    //         int newCol = col + deltaCol[i];
    //         if (newRow >= 0 and newCol >= 0 and newRow < n and newCol < m and grid[newRow][newCol] == 1 and vis[newRow][newCol] == 0) {
    //             dfs(newRow, newCol, carry, r0, c0);
    //         }
    //     }
    // };

    function<void(int, int, vector<pair<int, int>>&, int, int)> dfs = [&](int row, int col, vector<pair<int, int>>& carry, int r0, int c0) {
        carry.push_back({row - r0, col - c0});
        vis[row][col] = 1;
        int deltaRow[] = {0, 0, 1, -1};
        int deltaCol[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];
            if (newRow >= 0 and newCol >= 0 and newRow < n and newCol < m and grid[newRow][newCol] == 1 and vis[newRow][newCol] == 0) {
                dfs(newRow, newCol, carry, r0, c0);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 and !vis[i][j]) {
                vector<pair<int, int>> carry;
                dfs(i, j, carry, i, j);
                islands.insert(carry);
            }
        }
    }
    return islands.size();
}
// vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
// }
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size(), m = graph[0].size();
    vector<int> vis(n, 0);      // keeps tracks of visited noded
    vector<int> inStack(n, 0);  // keeps track of nodes that currently in ongoing dfs

    function<bool(int)> dfs = [&](int node) {
        if (inStack[node]) return true;
        if (vis[node]) return false;
        vis[node] = 1;
        inStack[node] = 1;
        for (auto it : graph[node]) {
            if (dfs(it) == true) return true;
        }
        inStack[node] = 0;
        return false;
    };

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        dfs(i);
        if (!inStack[i]) ans.push_back(i);
    }
    return ans;

    // map<int, int> safeNode;
    // for (int i = 0; i < n; i++) {
    //     if (graph[i].size() == 0) {
    //         safeNode[i] = 1;
    //     }
    // }
    // vector<int> ans;

    // function<bool(int)> rec = [&](int node) {
    //     if (pathVis[node]) return false;
    //     vis[node] = 1;
    //     pathVis[node] = 1;
    //     if (safeNode[node] == 1) {
    //         return true;
    //     }
    //     for (auto it : graph[node]) {
    //         if (!vis[it]) {
    //             if (rec(it) == false) {
    //                 return false;
    //             }
    //         } else if (pathVis[it]) {
    //             return false;
    //         }
    //     }
    //     pathVis[node] = 0;
    //     return true;
    // };

    // for (int i = 0; i < n; i++) {
    //     // if dfs(i) = a cycle is detected then we can't add this node to the answer
    //     if (!vis[i] and rec(i)) {
    //         ans.push_back(i);
    //         safeNode[i] = 1;
    //     }
    //     cout << "for i = " << i << endl;
    //     for (auto x : vis)
    //         cout << x << " ";
    //     cout << endl;
    //     for (auto x : pathVis)
    //         cout << x << " ";
    //     cout << endl;
    // }
    // return ans;
}
vector<int> findOrder(int n, vector<vector<int>>& pre) {
    // creat a graph from the prerequisites
    vector<int> adj[n];
    vector<int> store;
    for (auto it : pre) {
        // check directed graph
        if (find(adj[it[1]].begin(), adj[it[1]].end(), it[0]) != adj[it[1]].end()) {
            return store;
        }
        adj[it[1]].push_back(it[0]);
    }

    // check acyclic graph
    // to detect a cycle we need => nodeVis , pathVis
    vector<int> nodeVis(n, 0), pathVis(n, 0);
    function<bool(int node)> rec = [&](int node) {
        // if cyclic return true else false

        pathVis[node] = 1;
        nodeVis[node] = 1;
        for (auto it : adj[node]) {
            if (!(nodeVis[it]) and rec(it) == true) {
                return true;
            } else if (pathVis[it]) {
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < n; i++) {
        if (!nodeVis[i] and rec(i)) {
            // cycle detected
            return store;
        }
    }

    // apply topo sort
    // for topo sort -> we need vis array and stack
    vector<int> vis(n, 0);
    stack<int> st;
    function<void(int)> dfs = [&](int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                rec(it);
            }
        }
        st.push(node);
    };

    // always start from 0
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }
    if ((int)st.size() != n) {
        return store;
    }

    while (!st.empty()) {
        store.push_back(st.top());
        st.pop();
    }
    return store;
}
int ladderLength(string beginWord, string endWord,
                 vector<string>& wordList) {
    map<string, vector<string>> adj;

    map<string, int> f;
    for (auto it : wordList) {
        f[it]++;
    }
    map<string, int> vis;
    function<void(string, string)> dfs = [&](string node, string parent) {
        vis[node] = 1;
        for (int i = 0; i < node.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string temp = node;
                if (c == node[i])
                    continue;
                temp[i] = c;
                if (f[temp]) {
                    adj[node].push_back(temp);
                    if (!vis[temp]) {
                        dfs(temp, node);
                    }
                }
            }
        }
    };
    dfs(beginWord, "");
    for (auto it : adj) {
        cout << it.first << " -> ";
        for (auto x : it.second) {
            cout << x << " ";
        }
        cout << endl;
    }
    map<string, int> dist;
    dist[beginWord] = 1;
    queue<string> q;
    q.push(beginWord);
    while (!q.empty()) {
        string node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (dist.find(it) == dist.end()) {
                dist[it] = dist[node] + 1;
                q.push(it);
            } else if (dist[it] > dist[node] + 1) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist[endWord];
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    map<string, int> f;
    for (auto x : wordList) {
        f[x]++;
    }
    if (f[endWord] == 0)
        return {};
    f[beginWord] = 1;

    vector<vector<string>> ans;

    queue<pair<vector<string>, int>> q;
    int minDis = -1;
    q.push({{beginWord}, 1});
    while (!q.empty()) {
        auto [carry, dis] = q.front();
        q.pop();
        if (minDis != -1 and dis > minDis) {
            break;
        }
        string node = carry.back();
        if (node == endWord) {
            if (minDis == -1) {
                minDis = dis;
            }
            ans.push_back(carry);
            continue;
        }
        for (int i = 0; i < node.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string temp = node;
                if (c == node[i])
                    continue;
                temp[i] = c;
                if (f[temp]) {
                    vector<string> newCarry = carry;
                    newCarry.push_back(temp);
                    q.push({newCarry, dis + 1});
                }
            }
        }
    }

    if (ans.size() == 0) return {};

    return ans;
}
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

vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
    DSU ds(n * m);
    vector<int> ans;
    int cnt = 0;
    int vis[n][m];
    memset(vis, 0, sizeof(vis));
    int deltaRow[] = {0, 0, 1, -1};
    int deltaCol[] = {1, -1, 0, 0};

    for (auto it : operators) {
        int row = it[0], col = it[1];
        if (vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;//consider itself as a single island in the beginning
        for (int ind = 0; ind < 4; ind++) {
            int newRow = row + deltaRow[ind];
            int newCol = col + deltaCol[ind];
            if (newRow >= 0 and newCol >= 0 and newRow < n and newCol < m and vis[newRow][newCol] == 1) {//if any neighbour is a island cell
                ds.unionBySize(row * m + col, newRow * m + newCol);
                cnt--;
            }
        }
        ans.push_back(cnt);
    }

    return ans;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, int> mp;
    int n = accounts.size();
    DSU ds(n);
    for (int i = 0; i < n; i++) {
        vector<string> vec = accounts[i];
        for (int j = 1; j < vec.size(); j++) {
            if (mp.find(vec[j]) == mp.end()) {
                mp[vec[j]] = i;
            } else {
                ds.unionBySize(i, mp[vec[j]]);
            }
        }
    }

    vector<string> mergedMails[n];
    for (auto [x, y] : mp) {
        mergedMails[ds.ultimateParent(y)].push_back(x);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++) {
        vector<string> cur = mergedMails[i];
        if (cur.size() == 0) continue;
        string emailHolderName = accounts[i][0];
        sort(cur.begin(), cur.end());
        cur.insert(cur.begin(), emailHolderName);
        ans.push_back(cur);
    }
    return ans;
}

signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
// 660066