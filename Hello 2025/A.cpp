#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    long long T, n, m;
    cin >> T;
    while (T--) {
       cin >> n >> m;
       cout << max(n, m) + 1 << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}