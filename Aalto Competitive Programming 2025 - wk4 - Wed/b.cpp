#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 1;
long long n, q;
long long a[MAXN], check[MAXN];
vector<long long> result; 
 
void solve() {
    cin >> n >> q; 
    for (int i = 1; i <= n; i++) cin >> a[i];
    fill(check, check + MAXN, 0);
 
    int start = 1; 
 
    while(!check[start]) {
        result.push_back(start);
        check[start] = 1;
         
        start = a[start];
    }
    
    //cout << start << endl;
    //for (int i  = 0; i < result.size(); i++ ) cout << result[i] << ' ';
    long long length = 0;
    long long startLoop = n + 1;
    
    for (int i  = 0; i < result.size(); i++) {
        if (result[i] == start) {
            length = result.size() - i; 
            startLoop = i;
            break;
        }
    }
    //cout << endl << length << endl << startLoop << endl;
    
    for (int i = 1; i <= q; i++) {
        long long temp; 
        cin >> temp; 
        
        if (temp <= startLoop) cout << result[temp] << ' ';
        else {
            int curri = (temp - startLoop) % length;
            cout << result[curri + startLoop] << ' ';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}