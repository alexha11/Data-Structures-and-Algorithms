#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <=n; i++) {
            sort(a[i] + 1, a[i] + 1 + m);
        }
        vector<pair<int, int>> p;
        
        for (int i = 1; i <= n; i++) {
            p.push_back(make_pair(a[i][1], i)); 
        }
        
        sort(p.begin(), p.end());
        vector <int> ans; 
        for (const auto& pair : p) {
            ans.push_back(pair.second);
            // cout << pair.second << ' ';
        }
        // cout << endl;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         cout << a[i][j] << ' ';
        //     }
          
        // }
        int cur = -1;
        bool ok = true;
        for(int i = 1; i <= m; i++) {
            if (!ok) break;
            for (int j = 0; j < ans.size(); j++) {
                //cout << a[ans[j]][i] << ' ' << endl;
                if (a[ans[j]][i] <= cur) {
                    cout << -1 << endl;
                    ok = false;
                    break;
                }
                else {
                    cur = a[ans[j]][i];
                }
            }
        }
        if (ok) {
            for (const auto& value : ans) cout << value << ' '; 
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
