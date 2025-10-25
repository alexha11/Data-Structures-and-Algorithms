#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 1e5;
 
ll n;
ll a[MAXN];
 
void solve() {
   cin >> n; 
   
   for (int i = 1; i <= n; i++) cin >> a[i];
   
   ll ans1, ans2;
   ll res = -1;
   
   for (int i = 1; i < n; i++) {
       for (int j = i + 1; j <= n; j++) {
           unsigned long long prod = (unsigned long long)(a[i]) * (unsigned long long)(a[j]);
           int tem = __builtin_popcountll(prod);
           if (tem > res) {
               res = tem;
               ans1 = a[i];
               ans2 = a[j];
           }
       }
   }
   
   cout << res << endl;
   cout << ans1 << ' ' << ans2;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
