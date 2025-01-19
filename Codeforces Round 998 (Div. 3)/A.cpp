#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int a, b, c, d, e;
        int ans1 = 1, ans2 = 1;
        cin >> a >> b >> d >> e;
        
        c = a + b; 
        if (b + c == d) ans1++;
        if (c + d == e) ans1++;
        
        c = d - b;
        
        if (c + d == e) ans2++;
        
        cout << max(ans1, ans2) << endl;
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
