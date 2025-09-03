#include <bits/stdc++.h>
using namespace std;

vector<long long>f;

void backtracking (long long ans, long long a[21], long long i, long long n) {
    if (i == n) {
        //cout << ans << ' ';
        f.push_back(abs(ans));
        return;
    } 
    
    backtracking(ans + a[i], a, i + 1, n);
    backtracking(ans - a[i], a, i + 1, n);

}

void solve() {
  long long n;
  long long a[21];
  long long ans = 99999999999;
  cin >> n;
  for (long long i = 0; i < n; i++) {
      cin >> a[i];
  }
  backtracking(0, a, 0, n);
  for (long long i = 0; i < f.size(); i++) {
    if (f[i] < ans) ans = f[i];
  }
  //cout << endl;
  cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}