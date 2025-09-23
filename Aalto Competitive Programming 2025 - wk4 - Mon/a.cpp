#include <bits/stdc++.h>
using namespace std;
 
const int MAXN =2e5 + 1;
long long n, q, u, v;
long long f[MAXN], a[MAXN];
 
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] ^ a[i];
        //cout << f[i] << ' ';
    }
     
    for(int i = 1; i <= q; i++) {
        cin >> u >> v;
        long long temp =  f[u - 1] ^ f[v];
        cout << temp << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
Test details