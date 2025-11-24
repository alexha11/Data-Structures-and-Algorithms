#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 2e5 + 50;
 
ll n, s; 
ll a[MAXN], f[MAXN];

struct SafeHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
   cin >> n >> s; 
   f[0] = 0;
   for (int i = 1; i <= n; i++) {
       cin >> a[i];
       f[i] = f[i - 1] + a[i];
   }
   
   map<ll, ll, SafeHash> fr;
   ll res = 0;
   
   fr[0] = 1; 
   for (int i = 1; i <= n; i++) {
       if(fr.count(f[i] - s)) {
           res += fr[f[i] - s];
       }
       fr[f[i]]++;
   }
   
   cout << res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}

// 📌 Why exactly does the default unordered_map TLE?

// Because:

// It uses open addressing

// With large random inputs (~200k distinct prefix sums)

// Many prefix sums are large (up to ±10¹⁴)

// Many hashes collide

// Performance degrades to O(n) per operation

// So your solution becomes O(n²) ≈ 40 billion operations → TLE.