#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 1e3 + 1;
 
ll n, m;
 
void solve() {
   cin >> n >> m;
   
   if (n % 2 == 1 and m % 2 == 1) {
       cout << -1; 
       return;
   }
   
   if (m % 2 == 1) {
       cout << 'R';
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j < m - 1; j++) {
               if (i % 2 == 1) {
                   cout << 'R';
               } else {
                   cout << 'L';
               }
           }
           if (i != n) cout << 'D';
       }
       
       cout << 'L';
       for (int i = 1; i < n; i++) cout << 'U';
       
       return;
   }
   
   
   cout << 'D';
   for (int i = 1; i <= m; i++) {
       for (int j = 1; j < n - 1; j++) {
           if (i % 2 == 1) {
               cout << 'D';
           } else {
               cout << 'U';
           }
       }
       if (i != m) cout << 'R';
   }
   
   cout << 'U';
   for (int i = 1; i < m; i++) cout << 'L';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}