#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 5e3 + 1;
const int U = 20;

ll a[MAXN];
ll n, target;
bool ok = false; 

void solve() {
    cin >> n >> target;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<ll> cp;
    for (int i = 1; i <= n; i++) {
        cp.push_back(a[i]);
    }
    
    sort(a + 1, a + 1 + n);
    int tem1, tem2, tem3;
    
    for (int i = 1; i < n - 1; i++) {
        if(ok) break;

        for (int j = i + 1; j < n; j++) {
            if(ok) break;

            ll l = j + 1;
            ll r = n;
            while (l <= r) {
                if(ok) break;
                ll mid = (l + r) / 2;
            
                if (a[i] + a[j] + a[mid] == target) {
                    // cout << i << ' ' << j << ' ' << mid;
                    // return;
                    tem1 = a[i]; 
                    tem2 = a[j];
                    tem3 = a[mid];
                    ok = true;
                } else if (a[i] + a[j] + a[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
    }
    
    if (!ok) {
        cout << "IMPOSSIBLE";
    } else {
        int count1 = 0, count2 = 0, count3 = 0;
        for (int i = 0; i < n; i++) {
            if (cp[i] == tem1 and count1 == 0) {
                cout << i + 1 << ' ';
                count1++;
            } else if (cp[i] == tem2 and count2 == 0) {
                cout << i + 1 << ' ';
                count2++;
            } else if (cp[i] == tem3 and count3 == 0) {
                cout << i + 1 << ' ';
                count3++;
            }
        }
    }
  
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}