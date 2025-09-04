#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100001;
int f1[MAXN], f2[MAXN]; 

void solve() {
 int n, m, k;
 cin >> n >> m >> k;
 for (int i = 0; i < n; i++) cin >> f1[i];
 for (int i = 0; i < m; i++) cin >> f2[i];
 
 sort (f1, f1 + n);
 sort (f2, f2 + m);
 
 int l = 0, r = 0, res = 0;
 while(l < n and r < m) {
     if(f1[l] >= f2[r] - k and f1[l] <= f2[r] + k) {
         res++;
         l++;
         r++;
     } else if (f1[l] > f2[r] + k) {
         r++;
     } else if (f1[l] < f2[r] - k) {
         l++;
     }
 }
 cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}