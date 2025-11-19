#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;

ll n;
ll a, b;

ll mul(ll c, ll x) {
    if (x == 0) return 1;
    if (x == 1) return c % MOD;
    
    ll temp = mul(c, x / 2);
    temp = (temp * temp) % MOD;
    
    if (x % 2 == 1) {
        temp = (temp * c) % MOD;
    }
    
    return temp;
}

void solve() {
   cin >> n; 
   
   for (int i = 1; i <= n; i++) {
       cin >> a >> b;
       
       cout << mul(a, b) << endl;
   }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}