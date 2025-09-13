#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e6 + 1;
int n, f[MAXN], dp[MAXN];
 
void solve() {
    int n; 
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = f[2]; 
    for(int i = 4; i <= n; i++) {
        dp[i] = max(dp[i - 1], f[i - 1] + dp[i - 3]);
    }
    
    int res = 0;
     for(int i = 1; i <= n; i++) {
        if(dp[i] > res) res = dp[i];
    }
    cout << res; 
   
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
