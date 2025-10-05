#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 1e5 + 1;

vector<vector<pair<int, ll>>>a(MAXN);
priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<>> f; 
vector <ll> result(MAXN, INF);
int n, m;
int u, v;
ll l;

void solve() {
  cin >> n >> m;

  for(int i = 1; i <= m; i++) {
      cin >> u >> v >> l;
      a[u].push_back({v, l});
  }
  
  result[1] = 0;
  f.push({1, 0});
  
  while(!f.empty()) {
      auto [u, d] = f.top();
      f.pop();
      
      if (d > result[u]) continue;
      
      for (auto [v, w] : a[u]) {
            if (result[u] + w < result[v]) {
                result[v] = result[u] + w;
                f.push({v, result[v]});
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
  
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}