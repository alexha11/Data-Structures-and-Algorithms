#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 1e5 + 1;
 
int n, q;
int a[MAXN];
vector<int> state(MAXN, 0);
vector<int> result(MAXN, 1); 
int res = 0;
 
void dfs(int u) {
    state[u] = 1;
    if (state[a[u]] == 0) {
        res += 1;
        //cout << u << endl;
        dfs(a[u]);
    } else if (state[a[u]] == 1) {
        return;
    }
    
        
    state[a[u]] = 2;
    result[a[u]] = res;
}
 
void solve() {
  cin >> n >> q;
 
  for(int i = 1; i <= n; i++) {
      cin >> a[i];
  }
  
  for (int i = 1; i <= n; i++) {
      if(state[i] == 0) {
        res = 1;
        dfs(i);
        result[i] = res;
        //cout << "test" << i <<  endl;
      }
  }
 
  for (int i = 1; i <= q; i++) {
      int index;
      cin >> index;
      cout << result[index] << ' ';
  }
  
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
