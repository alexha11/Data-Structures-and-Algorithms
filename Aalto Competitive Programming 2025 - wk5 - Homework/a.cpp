#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

long long modpow(long long base, long long exp, long long mod = MOD) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n+1);
    vector<long long> prefix2(n+1, 0);
    vector<long long> pow2(n+1), invpow2(n+1);
    
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        prefix2[i] = prefix2[i-1] + (a[i] == 2);
    }
    
    pow2[0] = invpow2[0] = 1;
    long long inv2 = modpow(2, MOD-2);
    
    for (int i = 1; i <= n; i++) {
        pow2[i] = pow2[i-1] * 2 % MOD;
        invpow2[i] = invpow2[i-1] * inv2 % MOD;
    }

    long long ans = 0;
    long long sumInv = 0; 
    long long count1 = 0; 

    for (int j = 1; j <= n; j++) {
        if (a[j] == 1) {
            sumInv = (sumInv + invpow2[prefix2[j]]) % MOD;
            count1++;
        } else if (a[j] == 3) {
            int x = prefix2[j-1];
            long long temp = (pow2[x] * sumInv % MOD - count1 + MOD) % MOD;
            ans = (ans + temp) % MOD;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}