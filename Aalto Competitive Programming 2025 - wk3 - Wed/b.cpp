// #include <bits/stdc++.h>
// using namespace std;
// // clang-format off
// template<typename a, typename b> ostream& operator<<(ostream &os, const pair<a, b> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename t_container, typename t = typename enable_if<!is_same<t_container, string>::value, typename t_container::value_type>::type> ostream& operator<<(ostream &os, const t_container &v) { os << '{'; string sep; for (const t &x : v) os << sep << x, sep = ", "; return os << '}'; }
// void dbg_out() { cerr << endl; }
// template<typename head, typename... tail> void dbg_out(head h, tail... t) { cerr << ' ' << h; dbg_out(t...); }
// template <typename t> istream &operator>>(istream &is, vector<t> &v) { t value; is >> value; v.push_back(value); return is; }
// #define preamble ios::sync_with_stdio(0); cin.tie(0); dbg("init");
// // clang-format on
// #ifdef do_dbg
// #define dbg(...) cerr << "(" << #__va_args__ << "):", dbg_out(__va_args__)
// #else
// #define dbg(...)
// #endif
// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double ld;
// template <typename t> using v = vector<t>;
// template <typename t> using us = unordered_set<t>;
// template <typename k, typename v> using um = unordered_map<k, v>;
// constexpr int mod = 1e9 + 7;
// const int inf = 1e9;
// const ld eps = 1e-9;
// #define loop(n) for (int i = 0; i < n; i++)
// #define loopz(n) for (int z = 0; z < n; z++)
// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// #define sq(x) ((x) * (x))
 
// int n, k;
// v<int> a;
// v<bool> ready;
// v<ld> memo;
 
// // returns:
// // minimum time required to finish the track in seconds
// // parameter:
// // position on track (x100m)
// ld dp(int pos) {
//   if (pos >= n)
//     return 0;
//   if (ready[pos])
//     return memo[pos];
//   ld timeSpent1, timeSpent2;
//   // we can either:
//   // 1. not take the boost and move on to the next possible one
//   {
//     int newPos = pos + 1;
//     timeSpent1 =
//         1; // if we move 100m/s it takes a second to get to the next boost
//     timeSpent1 += dp(newPos);
//   }
//   // 2. take the boost
//   {
//     int newSpeed = a[pos];
 
//     // calculate distance and time to next decision
//     int newPos =
//         pos + newSpeed; // for example if it's 2x we go 200m with the boost
//     // but wait:
//     int distanceLeft = n - pos;
//     if (newSpeed >= distanceLeft) {
//       return (ld)distanceLeft / newSpeed;
//     }
//     // The player cannot pick up other boosts while one is in effect. After the
//     // boost ends, a player also cannot use the next k boost pads they pass.
//     timeSpent2 = 1;
//     // we then need to go k seconds without a boost at 100m/s
//     newPos += k;
//     timeSpent2 += k;
//     // since k is an integer we are already at a boost!
//     timeSpent2 += dp(newPos);
//   }
//   auto res = min(timeSpent1, timeSpent2);
//   memo[pos] = res;
//   ready[pos] = true;
//   return res;
// }
 
// int main() {
//   cin >> n >> k;
//   loop(n) cin >> a;
//   ready.resize(n);//
//   memo.resize(n);
//   cout << dp(0) << "\n";
// }

// #include <iostream>
// #include <iomanip>
 
// using namespace std;
 
// const int N = 1e5 + 5;
 
// int n, k;
// int a[N];
// long double f[N];
 
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);
//   cin >> n >> k;
//   for (int i = 0; i < n; i++) {
//     cin >> a[i];
//   }
//   f[n] = 0;
//   for (int i = n - 1; i >= 0; i--) {
//     // no use
//     f[i] = f[i + 1] + 1;
//     // use
//     if (a[i] >= n - i) {
//       f[i] = min(f[i], (long double)(n - i) / a[i]);
//     } else {
//       f[i] = min(f[i], 1 + (i + a[i] + k >= n ? n - (i + a[i]) : k + f[i + a[i] + k]));
//     }
//   }
//   cout << fixed << setprecision(6) << f[0] << '\n';
//   return 0;
