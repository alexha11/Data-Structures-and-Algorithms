
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

     
        sort(a.begin(), a.end());

        vector<int> frequencies;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                count++;
            } else {
                frequencies.push_back(count);
                count = 1;
            }
        }
        frequencies.push_back(count); 

        sort(frequencies.begin(), frequencies.end());

        int ans = 0;
        for (int freq : frequencies) {
            if (k >= freq) {
                k -= freq;
            } else {
                ans++;
            }
        }
        if (!ans) ans = 1;
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
