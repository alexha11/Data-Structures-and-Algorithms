#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 600;
 
ll n, q; 
ll a[MAXN][MAXN];
ll parent[MAXN];
ll res = 1e18;
vector<ll> maxSpan[MAXN];
vector<ll>final;
 
ll findMaxVertex(ll n, bool visited[], ll weights[])
{
    ll index = -1;
    ll maxW = INT_MIN;
 
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false and weights[i] > maxW) {
 
            maxW = weights[i];
            index = i;
        }
    }
    return index;
}
 
void createMaximumSpanningTree(ll n, ll graph[MAXN][MAXN])
{
    bool visited[MAXN];
    ll weights[MAXN];
 
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        weights[i] = INT_MIN;
    }
    
    weights[1] = INT_MAX;
    parent[1] = -1;
 
    for (int i = 1; i < n; i++) {
        int maxVertexIndex = findMaxVertex(n, visited, weights);
 
        visited[maxVertexIndex] = true;
 
        for (int j = 1; j <= n; j++) {
            if (graph[j][maxVertexIndex] != 0 and visited[j] == false) {
                if (graph[j][maxVertexIndex] > weights[j]) {
                    weights[j] = graph[j][maxVertexIndex];
                    parent[j] = maxVertexIndex;
                }
            }
        }
    }
}
 
void dfs(ll s, ll t, ll res, ll check[MAXN]) {
    if (s == t) {
        final.push_back(res);
        return;
    }
    
    
    for (auto v : maxSpan[s]) {
        // cout << v << ' ';
        if(!check[v]){
            check[v] = 1;
             dfs(v, t, min(res, a[s][v]), check);
        }
    }
}
 
void solve() {
    cin >> n >> q; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    createMaximumSpanningTree(n, a);
    
    for (int i = 2; i <= n; i++) {
        maxSpan[i].push_back(parent[i]);
        maxSpan[parent[i]].push_back(i);
        // cout << parent[i] << " - " << i << " \t"
        //      << a[i][parent[i]] << " \n";
    }
    
    for (int i = 1; i <= q; i++) {
        int s, t;
        res = 1e18;
        ll check[MAXN];
        for(int i = 1; i <= MAXN; i++) check[i] = 0;
        cin >> s >> t;
        check[s] = 1;
        dfs(s, t, res, check);
    }
    
    for (auto fi: final) {
        cout << fi << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}