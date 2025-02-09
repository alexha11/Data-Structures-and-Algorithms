class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // 1 3 5 4 7
        // 1 2 3 2
        int dp[2002];
        int ans[2002];
        int curMax = 1;
        for (int i = 0; i <= 2001; i++)
            dp[i] = 1;
        for (int i = 0; i <= 2001; i++)
            ans[i] = 1;

        for (int i = 1; i < nums.size(); i++) {
            int count = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    if (dp[j] == dp[i] - 1) {
                        count += ans[j];
                    }
                }
            }
            ans[i] = max(1, count);
            curMax = max(curMax, dp[i]);
        }

    

        //[1,3,5,4,7]
        // 1 2 3 3 4
        // 1 1 1 1 2
        // 1 1 1 2

        // 3 2 4 3 2
        // 1 1 2
        // 1 2 2

        // 1 1 2 2 1
        // 1 1 2 1 1
        for (int i = 0; i < nums.size(); i++) {
            cout << dp[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < nums.size(); i++) {
            cout << ans[i] << ' ';
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(dp[i] == curMax) sum += ans[i];
        }
        return sum;
    }
};