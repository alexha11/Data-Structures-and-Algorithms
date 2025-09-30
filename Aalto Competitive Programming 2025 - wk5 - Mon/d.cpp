#include <bits/stdc++.h>
using namespace std;

const int MAXN = 17;
long long result = 1e18;
long long n;
long long a[MAXN][MAXN];
long long check[MAXN];

struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

unordered_map<pair<int, int>, long long, PairHash> memo;

long long backtracking(long long a[MAXN][MAXN], long long check[MAXN], long long i, long long depth, long long ans, long long n, int mask) {
    if (depth == n) return ans;
    
    auto key = make_pair(mask, i);
    if (memo.find(key) != memo.end()) return ans + memo[key];
    
    long long best = 1e18;
    for (int j = 1; j <= n; j++) {
        if (!(mask & (1 << j))) { 
            best = min(best, backtracking(a, check, j, depth + 1, ans + a[i][j], n, mask | (1 << j)));
        }
    }
    
    memo[key] = best - ans; 
    return best;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) check[i] = 0; 
    
    for(int i = 1; i <= n; i++) {
        int mask = (1 << i);
        result = min(result, backtracking(a, check, i, 1, a[i][i], n, mask));
    }
    
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}