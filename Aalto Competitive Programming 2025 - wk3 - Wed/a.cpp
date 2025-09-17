#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 1;
long long n, m, a[MAXN], f[MAXN];
pair<long long, long long> dp[MAXN];
long long result[MAXN];

bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second < b.second;
}

void solve() {
   cin >> n >> m;
   for (int i = 1; i <= n; i++) {
        cin >> dp[i].first;
        dp[i].second = i;
   }
   
    for (int i = 1; i <= m; i++) {
       cin >> f[i];
   }
   dp[0].first = 0;
   int index = 1; 
   
   sort(dp + 1, dp + 1 + n);
   for(int i = 1; i <= n; i++) {
       if (dp[i].first != dp[i - 1].first) {
           while(dp[i].first > f[index] and index <= m) index ++;
           result[dp[i].second] = index;
       } else {
           result[dp[i].second] = index;
       }
   }
   
   for(int i = 1; i <= n; i++) {
       cout << result[i] << " ";
   }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}