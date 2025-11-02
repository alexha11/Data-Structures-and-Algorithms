#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18; 
const int MAXN = 1e6 + 1; 
 
ll n;
string s; 
vector<ll> z(MAXN, 0); 
 
void solve() {
    cin >> s; 
    n = s.length();
    
    ll l = 0, r = 0; 
    
    z[0] = n; 
 
    for (ll i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    for (int i = 0; i < n; i++) cout << z[i] << " ";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}