#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector <int> f[MAXN];
int check[MAXN], ans[MAXN];
bool ok = true;

void dfs(int i, int r){
    check[i] = 1;
    int res = r == 1 ? 2 : 1;
    
    if(!ans[i]) {
        ans[i] = res;
    } else {
        if(res == ans[i]) ok = false;
    }
    
    //cout << i << " " << res << endl;
    for (int v : f[i]) {
        if (ans[v] == ans[i]) ok = false;
        if(!check[v]) {
            dfs(v, res);
        }
    }
}

void solve() {
 int n, m;
 int u, v;
 cin >> n >> m;
 for (int i = 0; i < m; i++) {
     cin >> u >> v;
     f[u].push_back(v);
     f[v].push_back(u);
 }
 
 for(int i = 1; i <= n; i++) {
     if(!check[i]) {
          dfs(i, 2);
     }
 }
 
 if (!ok) {
     cout << "IMPOSSIBLE";
     return;
 }
 
 for (int i = 1; i <= n; i++) {
     cout << ans[i] << " ";
 }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}