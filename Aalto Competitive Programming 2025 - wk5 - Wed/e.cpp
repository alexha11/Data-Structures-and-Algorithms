#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int B = sqrt(n) + 1;  // threshold between small and large
    vector<int> ans(n+1, 0);

    // store trains with small periods
    vector<vector<int>> cnt(B+1, vector<int>(B+1, 0));

    for (int i = 1; i <= n; i++) {
        if (a[i] <= B) {
            cnt[a[i]][i % a[i]]++;
        } else {
            // large period -> simulate directly
            for (int day = i; day <= n; day += a[i]) {
                ans[day]++;
            }
        }
    }

    // process small periods
    for (int d = 1; d <= n; d++) {
        for (int p = 1; p <= B; p++) {
            ans[d] += cnt[p][d % p];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
