#include <bits/stdc++.h>
#define MAXSUM 1000001 

using namespace std;

typedef long long ll; 
const ll INF = 1e18;
const int MAXN1 = 1e5 + 1;
const int MAXN2 = 1e5;

struct Point {
    ll x, y;
};

ll n;
Point a[MAXN1], b[MAXN1];

void solve() {
    cin >> n;
    
    ll horizontalLines = 0, verticalLines = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
        
        if (a[i].x == b[i].x) verticalLines++;
        if (a[i].y == b[i].y) horizontalLines++;
    }
    
    cout << verticalLines * horizontalLines;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
