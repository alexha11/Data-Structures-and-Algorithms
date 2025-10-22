// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// const int N = 505;
// ll n, m;
// vector<vector<ll>> weigh(N, vector<ll>(N, 0));
// vector<vector<ll>> adj(N);

// ll flow = 0;
// vector<ll> parent(N);
// ll new_flow;
// vector<vector<ll>> ans(N);

// ll bfs(ll s, ll t, vector<ll>& parent) {
//     fill(parent.begin(), parent.end(), -1);
//     parent[s] = -999;
//     queue<ll> q;
//     q.push(s);

//     while (!q.empty()) {
//         ll cur = q.front();
//         q.pop();

//         for (ll next : adj[cur]) {
//             if (parent[next] == -1 && weigh[cur][next] > 0) {  
//                 parent[next] = cur;
//                 if (next == t) return 1;
//                 q.push(next);
//             }
//         }
//     }
//     return 0;
// }

// ll maxflow(ll s, ll t) {
//     while ((new_flow = bfs(s, t, parent))) {
//         flow++;
//         ll cur = t;
//         vector<ll> path;   
//         path.push_back(cur);
//         while (cur != s) {
//             ll prev = parent[cur];
//             weigh[prev][cur]--;   
//             weigh[cur][prev]++;  
//             cur = prev;
//             path.push_back(cur);
//         }
//         reverse(path.begin(), path.end()); 
//         ans[flow] = path;                 
//     }
//     return flow;
// }

// void solve() {
//     cin >> n >> m;
//     for (int i = 0; i < m; i++) {
//         ll a, b;
//         cin >> a >> b;
//         if(!weigh[a][b]) {
//             adj[a].push_back(b);  
//             weigh[a][b]++;
//         }
//     }

//     int amount = maxflow(1, n);
//     cout << amount << endl;
//     for (int i = 1; i <= amount; i++) {
//         cout << ans[i].size() << endl;
//         for (ll x : ans[i]) cout << x << ' ';
//         cout << endl;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505;
ll n, m;
vector<vector<ll>> capacity(N, vector<ll>(N, 0)); 
vector<vector<ll>> adj(N);

ll flow = 0;
vector<ll> parent(N);
vector<vector<ll>> paths;

bool bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q; 
    q.push({s, LLONG_MAX});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll min_cap = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                ll new_min_cap = min(min_cap, capacity[cur][next]);
                
                if (next == t) {
                    ll cur_node = t;
                    while (cur_node != s) {
                        ll prev = parent[cur_node];
                        capacity[prev][cur_node] -= new_min_cap;
                        capacity[cur_node][prev] += new_min_cap;
                        cur_node = prev;
                    }
                    flow += new_min_cap;
                    return true;
                }
                q.push({next, new_min_cap});
            }
        }
    }
    return false;
}

void dfs(ll u, ll t, vector<ll>& path, vector<bool>& visited) {
    path.push_back(u);
    visited[u] = true;
    
    if (u == t) return;
    
    for (ll v : adj[u]) {
        if (!visited[v] && capacity[u][v] == 0 && capacity[v][u] > 0) {
            capacity[v][u]--; 
            dfs(v, t, path, visited);
            return;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        if (capacity[a][b] == 0) {
            adj[a].push_back(b);
            adj[b].push_back(a); 
        }
        capacity[a][b]++;
    }

    while (bfs(1, n, parent)) {
    }

    cout << flow << endl;
    
    for (int i = 0; i < flow; i++) {
        vector<ll> path;
        vector<bool> visited(n + 1, false);
        dfs(1, n, path, visited);
        paths.push_back(path);
    }
    
    for (const auto& path : paths) {
        cout << path.size() << endl;
        for (ll x : path) cout << x << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}