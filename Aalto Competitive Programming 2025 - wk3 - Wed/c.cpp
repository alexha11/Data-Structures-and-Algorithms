#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 1;
long long n, m, a[MAXN], f[MAXN];
pair<long long, long long> dp[MAXN];
long long result[MAXN];
long long res = 0;

void solve() {
   cin >> n; 
   for (int i = 1; i <= n; i++) {
       cin >> a[i];
       res += a[i];
   }
   long long temp =  ((n - 1) * n / 2);
   //cout << res << ' ' << temp;
   res -= temp;
   if (res <= 0) {
       cout << "Uolevi";
       return; 
   }
   
   if (res % 2 == 0) {
         cout << "Uolevi";
   } else {
    
        cout << "Maija";
   }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}