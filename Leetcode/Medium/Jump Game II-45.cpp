// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int dp[10001];
//         for (int i = 0; i <= 10000; i++) dp[i] = 9999;
//         dp[0] = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = 1; j <= nums[i] and i + j < nums.size(); j++) {
//                 dp[i + j] = min(dp[i + j], dp[i] + 1); 
//                 cout << dp[i + j] << ' ' << i + j << ' ' << dp[i] << ' ' << i << endl;
//             }
//         }
//         return dp[nums.size() - 1];
//     }
// };
// O(n^2) solution, TLE

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        int ans = 0, farthest = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            farthest = max(farthest, i + nums[i]); 

            if (i == cur) {
                ans++;
                cur = farthest;

                if (cur >= n - 1) break;
            }
        }        

        return ans;
    }
};