#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> C;
typedef vector<double> vd;
 
void fft(vector<C>& a) {
int n = sz(a), L = 31 - __builtin_clz(n);
static vector<complex<long double>> R(2, 1);
static vector<C> rt(2, 1); // (^ 10% fas te r i f double)
for (static int k = 2; k < n; k *= 2) {
R.resize(n); rt.resize(n);
auto x = polar(1.0L, acos(-1.0L) / k);
rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
}
vi rev(n);
rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
for (int k = 1; k < n; k *= 2)
for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
C z = rt[j+k] * a[i+j+k]; // (25% fas te r i f hand=ro l led )
a[i + j + k] = a[i + j] - z;
a[i + j] += z;
}
}
 
vd conv(const vd& a, const vd& b) {
if (a.empty() || b.empty()) return {};
vd res(sz(a) + sz(b) - 1);
int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
vector<C> in(n), out(n);
copy(all(a), begin(in));
rep(i,0,sz(b)) in[i].imag(b[i]);
fft(in);
for (C& x : in) x *= x;
rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
fft(out);
rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
return res;
}
 
 
int main() {
//  vd test = conv(vector2, vector3);
 vd vectora, vectorb;
 string a, b;
 cin >> a >> b;
 for (int i = 0; i < a.size(); i++) {
     double temp =  (a[i] - '0');
     vectora.push_back(temp);
 }
 for (int i = 0; i < b.size(); i++) {
     double temp =  (b[i] - '0');
     vectorb.push_back(temp);
 }
 
 vd test = conv(vectora, vectorb);
 for (auto i : test) cout << i;
}
