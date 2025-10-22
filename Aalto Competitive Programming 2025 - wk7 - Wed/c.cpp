#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
 
    // Topological sort using Kahn's algorithm
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);
 
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
 
    // DP for longest path
    vector<int> dist(n + 1, -1e9);
    vector<int> parent(n + 1, -1);
 
    dist[1] = 1; // city 1 as starting point
    for (int u : topo) {
        if (dist[u] < 0) continue;
        for (int v : adj[u]) {
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }
 
    if (dist[n] < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    // Reconstruct path
    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());
 
    cout << path.size() << "\n";
    for (int city : path)
        cout << city << " ";
    cout << "\n";
 
    return 0;
}
