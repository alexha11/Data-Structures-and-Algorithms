#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 1;
long long n, f[MAXN], dp[MAXN];
 
void solve() {
    int n; 
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        dp[i] = dp[i - 1] + f[i];
    }
    
    long long minn = 9999999999, maxx = -9999999999;
    long long res = -9999999999;
    long long indexa = 0, indexb = 0;
    for (int i = 1; i <= n; i++) {
        minn = min (dp[i - 1], minn);
        
        res = max (dp[i] - minn, res);
 
    }
    
    cout << res;
    
   
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}