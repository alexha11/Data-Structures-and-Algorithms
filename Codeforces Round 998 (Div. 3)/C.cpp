#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> x(n);
        unordered_map<int, int> freq;
        
        // Read input and populate frequency map
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            freq[x[i]]++;
        }
        
        int score = 0;
        
        for (auto &[num, count] : freq) {
            // cout << num << ' ' << count << endl;
            int complement = k - num; 
            if (freq.find(complement) != freq.end()) {
                int pairs = min(count, freq[complement]);
                if (num == complement) {
                    pairs /= 2;
                }
                score += pairs;

                freq[num] -= pairs;
                freq[complement] -= pairs;
            }
        }
        
        cout << score << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
