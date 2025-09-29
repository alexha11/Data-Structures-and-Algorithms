#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 17;
long long result = 1e18;
long long n;
long long a[MAXN][MAXN];
long long check[MAXN];

map<pair<int,int>, long long> memo;

long long backtracking (long long a[MAXN][MAXN], long long check[MAXN], long long i, long long depth, long long ans, long long n, int mask) {
    if (depth == n) return ans;
    
    auto key = make_pair(mask, i);
    if (memo.count(key)) return ans + memo[key];
    
    long long best = 1e18;
    for (int j = 1; j <= n; j++) {
        if (!(mask & (1 << j))) { 
            best = min(best, backtracking(a, check, j, depth + 1, ans + a[i][j], n, mask | (1 << j)));
        }
    }
    
    memo[key] = best - ans; 
    return best;
}
 
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) check[i] = 0; 
  
  for(int i = 1; i <= n; i++) {
    int mask = (1 << i);
    result = min(result, backtracking(a, check, i, 1, a[i][i], n, mask));
  }
  
  cout << result;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
