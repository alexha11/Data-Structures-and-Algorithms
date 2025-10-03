#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 51;
int n;
int a[MAXN];
int s = 0;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    
    if (s & 1) {
        cout << "no";
        return;
    }
    int temp = 0;
    for (int i = 1; i <= n; ++i) temp = max(temp, a[i]);
    if (temp > s / 2) {
        cout << "no";
        return;
    }
    
    priority_queue<pair<int,int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 0) pq.push({a[i], i});
    }

    vector<pair<int,int>> result;
    while ((int)pq.size() >= 2) {
        auto p1 = pq.top(); pq.pop();
        auto p2 = pq.top(); pq.pop();

        result.push_back({p1.second, p2.second});
        if (--p1.first > 0) pq.push(p1);
        if (--p2.first > 0) pq.push(p2);
    }
    
    if (pq.size()) {
        cout << "no";
        return;
    }

    cout << "yes" << endl;
    for (auto &mv : result) {
        cout << mv.first << " " << mv.second << endl;
    }

    
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}
