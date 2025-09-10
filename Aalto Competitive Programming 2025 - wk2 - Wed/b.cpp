#include <bits/stdc++.h>
using namespace std;

bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}

void solve() {
    int n; 
    cin >> n;
    vector<long long> a;
    vector<long long> b;
    vector< pair<int,int > > v;
    
    
   for (int i = 1; i <= n; i++) {
      int l, r;
    cin >> l >> r;
    v.push_back({l, r});
   }
    
   sort(v.begin(),v.end(),myComparison);


    long long indexa = 0;
    long long indexb = 1;
    int res = 0;
    while (indexb < n) {
        if(v[indexa].second <= v[indexb].first) {
            res++;
            indexa = indexb;
            indexb++;
        } else {
            indexb++;
        }
    }

    cout << res + 1;
    
    
    
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}