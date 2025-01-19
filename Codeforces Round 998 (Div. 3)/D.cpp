#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int n; 
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        int cur = a[1];
        bool ok = true;
        for (int i = 2; i <= n; i++) {
            if (cur > a[i]) {
                cout << "NO" << endl;
                ok = false;
                break;
            } else {
                cur = a[i] - cur;
            }
        }
        
        if(ok) {
            cout << "YES" << endl;
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
