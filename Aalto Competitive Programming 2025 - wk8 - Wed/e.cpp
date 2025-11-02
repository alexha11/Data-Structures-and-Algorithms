#include <bits/stdc++.h>
using namespace std;
 
# define MAXSUM 1000001 
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN1 = 1e5 + 1;
const int MAXN2 = 1e5;
 
ll n, q; 
ll a[MAXN1];
vector<ll> f(MAXN2, 0);
bitset<MAXSUM> bit;
 
void solve() {
   cin >> n >> q; 
   
   for (int i = 1; i <= n; i++) {
       cin >> a[i]; 
   }
    
    bit.reset(); 
 
    bit[0] = 1; 
    for (int i = 1; i <= n; i++) bit |= (bit << a[i]);
    
    for (int i = 1; i <= q; i++) { 
        int temp;
        cin >> temp;
 
        bit[temp]? cout << "Yes " : cout << "No "; 
    } 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}