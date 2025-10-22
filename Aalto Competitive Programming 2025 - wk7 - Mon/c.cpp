#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<set<int>> forbidden(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        forbidden[a].insert(b);
        forbidden[b].insert(a);
    }

    vector<int> parent(n + 1, -1);
    set<int> unvisited;
    for (int i = 2; i <= n; i++) unvisited.insert(i);

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        vector<int> to_remove;
        for (int v : unvisited) {
            if (forbidden[u].count(v) == 0) {  // path not forbidden
                parent[v] = u;
                q.push(v);
                to_remove.push_back(v);
            }
        }
        for (int v : to_remove) unvisited.erase(v);
    }

    if (parent[n] == -1) {
        cout << 0 << "\n";  // no path
    } else {
        vector<int> path;
        for (int cur = n; cur != -1; cur = parent[cur]) path.push_back(cur);
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int x : path) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
