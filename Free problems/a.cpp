#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 2e5 + 50;
 
ll n; 
vector<ll> a;

void solve() {
   cin >> n;
   
   for (int i = 1; i <= n; i++) {
       ll temp;
       cin >> temp; 
       a.push_back(temp);
   }
   
   sort(a.begin(), a.end());
   
   ll s = 1;
   for (auto t : a) {
       if (t > s) {
            break;        
       }
       
       s += t;
   }
   
   cout << s;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}