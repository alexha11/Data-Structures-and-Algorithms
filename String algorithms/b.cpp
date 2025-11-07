#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
 
#define REP(i,a,b) for (ll i = a; i < b; i++)
 
 
vector<ll> z(string s) {
    ll n = s.size();
    vector<ll> z(n);
    ll x = 0, y = 0;
    for (ll i = 1; i < n; i++) {
        z[i] = max(0LL, min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}
 
int main() {
    string a, p;
    cin >> p >> a;
 
    string pa = p + "#" + a;
    //cout << p.size() << endl;
 
    vector<ll> z_v(pa.size());
    z_v = z(pa);
    vector<ll> out;
    REP(i,0,(ll)z_v.size()) {
        if(z_v[i] == p.size()) out.push_back(i-p.size());
        //cout << c << " ";
    }
    cout << out.size() << endl;
    for(auto pos : out) {
        cout << pos << " ";
    }
    cout << endl;
}