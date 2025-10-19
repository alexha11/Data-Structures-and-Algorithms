#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505;
ll n, m;
vector<vector<ll>> weigh(N, vector<ll>(N, 0));
vector<vector<ll>> adj(N);

long long flow = 0;
vector<long long> parent(N);
long long new_flow;

ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -9;
    queue<pair<ll, ll>> q;
    q.push({s, LLONG_MAX});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && weigh[cur][next] > 0) {
                parent[next] = cur;
                ll new_flow = min(flow, weigh[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

ll maxflow(ll s, ll t) {
    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            weigh[prev][cur] -= new_flow;
            weigh[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);

        weigh[a][b] += c;
    }
    cout << maxflow(1, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}