#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 1;
long long n, a[MAXN], f[MAXN];
 
void solve() {
    int n, m, k; 
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    
    int res = 0;
    for(int i = 1; i <= k; i++) {
        res = res % n;
        
        if (f[res]) {
            res = res + 2;
        } else {
            res = res + 1;
        }
    }
    
    cout << (res % n) * 100 ;
    
   
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
