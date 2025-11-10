#include <bits/stdc++.h>
using namespace std;
 
# define MAXSUM 1000001 
typedef long long ll; 
 
const ll INF = 1e18;
const int MAXN1 = 1e3 + 1;
const int MAXN2 = 1e5;

struct Point {
    ll x, y;
};

ll n;
Point a[MAXN1];


ll calculatePoly (Point a[MAXN1], ll n) {
    ll c = 0;
    
    int j = n; 
    
    for (int i = 1; i <= n; i++) {
        c += (a[i].x + a[j].x) * (a[j].y - a[i].y);
        j = i;
    }
    
    return abs(c);
}

void solve() {
  cin >> n;
  
  for(int i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].y;
  }
  
  cout << calculatePoly(a, n);
  
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}