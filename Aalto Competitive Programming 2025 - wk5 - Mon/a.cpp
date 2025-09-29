#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 1;
long long n;
long long res = 0;
 
void solve() {
    cin >> n;
    while (n > 0) {
        string tempt = to_string (n);
        int nu = 0; 
        for (int i = 0; i < tempt.length(); i++) {
            int num = tempt[i] - '0';
            if (num >= nu) nu = num;
        }
        //cout << nu << endl;
        n -= nu;
        res++;
    }
    
    cout << res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}