#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n;
  long long a[100001];
  long long ans = 0;
  
  cin >> n;
  a[1] = 1;
  a[2] = 1;
  
  for (long long i = 3; i <= n; i++) a[i] = (a[i - 1] + a[i - 2]) % 998244353;
  
  for (long long i = 1; i <= n; i++) {
      ans += (a[i] % 998244353);

  }
  
  cout << (ans + 1) % 998244353;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}