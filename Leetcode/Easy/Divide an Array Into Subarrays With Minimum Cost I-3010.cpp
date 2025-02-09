class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans1 = nums[0];
        int ans2 = 51;
        int ans3 = 51;

        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (ans2 > nums[i]) {
                ans2 = nums[i];
                index = i;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (ans3 > nums[i] and i != index) {
                ans3 = nums[i];
            }
        }
        cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
        return ans1 + ans2 + ans3;
    }
};