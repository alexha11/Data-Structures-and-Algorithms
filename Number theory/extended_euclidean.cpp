#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// find gcd (a, b) and coefficients x, y such that xa + yb = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    ll x1, y1;
    ll gcd = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

ll modInverse(ll a, ll m) {
    if (a == 0) return -1;
    
    ll x, y;
    ll gcd = extgcd(a, m, x, y);
    
    if (gcd != 1) {
        return -1;
    }
    
    //incase x is negative
    x = (x % m + m) % m;
    
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, m;
    cin >> a >> m;
    
    cout << modInverse(a, m) << endl;
    
    return 0;
}