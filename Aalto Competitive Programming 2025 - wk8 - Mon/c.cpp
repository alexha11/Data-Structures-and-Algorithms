#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 1e5 + 1;
 
ll n;
vector<ll> check(MAXN, 0);
ll res = 0;

void solve() {
   cin >> n; 
   vector<pair<ll, ll>>a(n);

   for (int i = 0; i < n; i++) {
       cin >> a[i].first;
       a[i].second = i;
   }
   
    sort(a.begin(), a.end());

   for (int i = 0; i < n; i++) {
       if(check[i] and a[i].second == i) continue;
       
       ll temp = i;
       ll co = 0;
       while(!check[temp]) {
           check[temp] = 1;
           temp = a[temp].second;
           co++;
       }
        if (co > 1) res += (co - 1);
   }
   
   cout << res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}