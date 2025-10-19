#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 2e5 + 1;
const int U = 20;
 
int f[MAXN][U];
int n, q;
vector<int>depth(MAXN, 0);
vector<int>a[MAXN];
 
// void query(int u, int k) {
//     for (int i = 0; i <= U; i++) {
//         if ((k >> i) & 1) {
//             u = f[u][i];
//         }
//     }
    
//     return u;
// }
 
void preprocessing() {
    for (int i = 1; i < U; i++) {
        for (int j = 2; j <= n; j++) {
            f[j][i] = f[f[j][i - 1]][i - 1];
            // cout << f[f[j][i - 1]][i - 1] << ' ' << f[j][i - 1] << ' ' << i << ' ' << j << endl; 
        }
    }
}
 
void DFS (int u) {
    for (auto v : a[u]) {
        depth[v] = depth[u] + 1;
        // cout << depth[v] << ' ' << v <<  endl;
        DFS(v);
    }
}
 
int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    // cout << depth[a] << ' ' << depth[b] << endl;
    int k = depth[a] - depth[b];
    
    for (int i = 0; i < U; i++) {
        if((k >> i) & 1) {
            // cout << f[a][i] << ' ' << a << ' ' << i <<  endl;
            a = f[a][i];
        }
    }
    
    if (a == b) return a;
    
    for (int i = U - 1; i >= 0; i--) {
        if (f[a][i] != f[b][i]) {
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
    
    
    
    
}
 
void solve() {
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
      int tempt; 
      cin >> tempt;
      
      f[i][0] = tempt;
    //   cout << f[i][0] << " test" << endl;
      a[tempt].push_back(i);
  }
  
  depth[1] = 1; 
  DFS(1);
  preprocessing();
  
  for (int i = 1; i <= q; i++) {
      int a, b;
      cin >> a >> b; 
      cout << LCA(a, b) << endl; 
  }
  
  
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}