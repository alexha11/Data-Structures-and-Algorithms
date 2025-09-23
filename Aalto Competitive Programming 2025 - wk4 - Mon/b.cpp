#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e3 + 1;
long long n, q;
long long r2, r1, c2, c1;
long long f[MAXN][MAXN];
 
void solve() {
    cin >> n >> q; 
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char st;
            cin >> st;
            if (st == '.') f[i][j] = 0;
            else f[i][j] = 1;
            
            f[i][j] += f[i - 1][j];
            f[i][j] += f[i][j - 1];
            f[i][j] -= f[i - 1][j - 1];
        }
    }
    
    //  for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for (int i = 1; i <= q; i++) {
        cin >> r1 >> c1 >> r2 >> c2 ;
        cout << f[r2][c2] - f[r1-1][c2] - f[r2][c1-1] + f[r1-1][c1-1] << endl;
 
    }
    
  
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
