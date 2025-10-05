#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 1e5 + 1;
 
vector<vector<int>>a(MAXN);
int n, m;
int u, v;
vector<int> result;
vector<int> state(MAXN, 0);
bool ok = true;
 
void dfs(int u) {
    
    for (auto v : a[u]) {
        if(state[v] == 0) {
            //cout << u << ' ' << v << endl;
            state[v] = 1;
            dfs(v);
            if (!ok) return;
        }
        else if (state[v] == 1) {
            ok = false;
            cout << "IMPOSSIBLE";
            return;
        }
    }
    
    state[u] = 2;
    result.push_back(u);
}
 
void solve() {
  cin >> n >> m;
 
 
  for(int i = 1; i <= m; i++) {
      cin >> u >> v;
      a[u].push_back(v);
  }
  
  
  for (int i = 1; i <= n; i++) {
      if(state[i] == 0) {
        dfs(i);
      }
      
      if (!ok) return;
  }
  
  
  
  for (int i = result.size() - 1; i >= 0; i--) cout << result[i] << ' ';
  
  
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}