#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 1e5 + 1;
 
vector<vector<pair<int, ll>>>a(MAXN);
queue<int> f; 
vector <ll> result(MAXN, 0);
int n, m;
int u, v;
ll l;
vector <ll> check(MAXN, 0);
bool visited[MAXN];
 
void solve() {
  cin >> n >> m;
 
  for(int i = 1; i <= m; i++) {
      cin >> u >> v >> l;
      a[u].push_back({v, l});
      a[v].push_back({u, l});
  }
  
  result[1] = INF;
  f.push(1);
  check[1] = 1;
  
  while(!f.empty()) {
    auto u = f.front();
    f.pop();
    
    for (auto [v, w] : a[u]) {
        int cr = min(w, result[u]);
        if (cr > result[v]) {
            //cout << "test " << u << ' ' << v << ' ' << w << endl;
            result[v] =  cr;
            f.push(v);
        }
    }
  }
    
    for(int i = 2; i <= n; i++) {
        cout << result[i] << ' ';
    }
  
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}