#include <bits/stdc++.h>
using namespace std;
 
const int MAXN =(2e5 + 1) * 4; // maximum index size is 4n 
long long n, q, t, a, b;
long long f[MAXN];

void update(long long x, long long l, long long r, long long u, long long v) {
    if (l > u or u > r) return;
    
    if (l == r) {
        f[x] = v;
        return;
    }
    
    long long mid = (l + r) / 2;
    // cout << l << ' ' << mid << ' ' << r << endl; 
    
    update(x * 2, l, mid, u, v);
    update(x * 2 + 1, mid + 1, r, u, v);
    
    f[x] = min(f[x * 2], f[x * 2 + 1]);
}

long long find(long long x, long long l, long long r, long long u, long long v) {
    if (r < u or l > v or l > r) return 1e18;
    if (l >= u and r <= v) return f[x];
    
    long long mid = (l + r) / 2;
    return min(find(x * 2, l, mid, u, v), find(x * 2 + 1, mid + 1, r, u, v));
}

void solve() {
    cin >> n >> q;
    
    fill(f, f + MAXN, (long long)1e18);
    for(int i = 1; i <= n; i++) {
        long long temp;
        cin >> temp;
        update(1, 1, n, i, temp);
    }
    
    for(int i = 1; i <= q; i++) {
        cin >> t >> a >> b;
        
        if (t == 1) {
            update(1, 1, n, a, b);
        } else {
            cout << find(1, 1, n, a, b) << endl;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}