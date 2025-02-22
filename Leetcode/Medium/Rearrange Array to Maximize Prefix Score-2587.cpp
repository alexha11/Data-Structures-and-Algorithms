class Solution {
public:
    int maxScore(vector<int>& nums) {
        long long ans = 0;
        long long count = 0;

        vector<int> f;
        for (long long num : nums) {
            if (num > 0) {
                ans += num;
                count++;
            } else {
                f.push_back(abs(num));
            }
        }
        cout << ans << ' ';
        sort(f.begin(), f.end());

        for (long long num : f) {
            if (ans - num > 0) {
                ans -= num;
                count++;
                cout << ans << ' ';
            }
        }
        
        return count;
    }
};