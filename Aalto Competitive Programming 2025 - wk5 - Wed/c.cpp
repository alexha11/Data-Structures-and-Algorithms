#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 1;
unsigned long long n;
vector<int> f;
 
void solve() {
  cin >> n; 
 
  if (n == 1) {
      cout << 0;
      return;
  }
 
  f.push_back(2);
  while (n > 1) {
      if (n == 4) {
          n -= 3;
          f.push_back(0);
      }
      else if(n % 2 == 0) {
          n = n / 2;
          f.push_back(1);
      } else {
          n -= 3;
          f.push_back(0);
      }
  }
 
  if (n != 1) {
      cout << 0;
      return;
  }
  
  cout << f.size() << endl;
  for(int i = f.size() - 1; i >= 0; i--) {
      if (f[i] == 1) cout << "MUL" << endl;
      if (f[i] == 0) cout << "ADD" << endl;
      if (f[i] == 2) cout << "END" << endl;
  }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}