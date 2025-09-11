#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve() {
    int n;
    cin >> n;

    vector<long long> dp(n+1, 0);
    dp[0] = 1; 

    for (int i = 1; i <= n; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }

    cout << dp[n];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
