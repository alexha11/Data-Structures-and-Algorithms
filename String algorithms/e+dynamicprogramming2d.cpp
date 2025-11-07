#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
const int N = 5e2 + 5;
 
int n, k;
pair<int, int> s[N];
int g[N];
long long f[N][N];
int q[N][N];
 
long long cost(int l, int r) {
  return 1LL * s[l].first * (r - l + 1);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].first;
    s[i].second = i;
  }
  sort(s + 1, s + n + 1);
  memset(f, -0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int p = i; p >= 1; p--) {
        if (cost(p, i) + f[p - 1][j - 1] > f[i][j]) {
          f[i][j] = cost(p, i) + f[p - 1][j - 1];
          q[i][j] = p;
        }
      }
    }
  }
  int x = n, y = k;
  int ptr = 1;
  while (y > 0) {
    int l = q[x][y];
    for (int z = l; z <= x; z++) {
      g[s[z].second] = ptr; 
    }
    x = l - 1;
    y--;
    ptr++;
  }
  for (int i = 1; i <= n; i++) {
    cout << g[i] << ' ';
  }
  return 0;
}