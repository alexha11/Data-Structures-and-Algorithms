#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector <int> f[MAXN];
vector <int> ans;
int check[MAXN];

void dfs(int i){
    check[i] = 1;
    for (int v : f[i]) {
        if(!check[v]) {
            dfs(v);
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
 
 for (int i = 1; i <= n; i++) {
     if (!check[i]) {
         dfs(i);
         ans.push_back(i);
     }
 }
 cout << ans.size() - 1 << endl;
 for (int i = 0; i < ans.size() - 1; i++) {
     cout << ans[i] << ' ' << ans[i + 1] << endl;
 }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}