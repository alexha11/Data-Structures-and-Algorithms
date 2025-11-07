#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
const ll INF = 1e18;
const int MAXN = 1e5 + 1;
 
string s, t;
int ar1[200], ar2[200];
 
void solve() {
   cin >> s >> t;
   
   if (s.length() < t.length()) {
       cout << "No";
       return;
   }
   
   for (int i = 0; i < s.length(); i++) {
       int ia = (int)s[i];
       ar1[ia]++;
   }
   
   for (int i = 0; i < t.length(); i++) {
       int ia = (int)t[i];
       ar2[ia]++;
   }
   
  for (int i = 97; i <= 122; i++) {
      if (ar1[i] < ar2[i]) {
       cout << "No";
       return;
    }
  }
  
  int indexb = 0;
  int miss = 0;
  for (int i = 0; i < s.length(); i++) {
      if (s[i] == t[indexb] and indexb < t.length()) indexb++;
      else miss++;
  }
//   cout << indexb << ' ' << miss << endl;
  
  if (indexb != t.length()) {
      cout << "No";
      return;
  } 
  if (miss + t.length() != s.length()) {
      cout << "No";
      return;
  }
    
  cout << "Yes";
    
   
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
