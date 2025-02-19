class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0, end = 0;
        vector<string> ans;

        if (nums.size() == 0) {
            return {};
        }

        if (nums.size() == 1) {
            string final = to_string(nums[0]);
            return {final};
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + 1 != nums[i + 1] && end < nums.size()) {
                string a = to_string(nums[start]);
                string b = to_string(nums[end]);
                string final = start != end ? a + '-' + '>' + b : a;
                ans.push_back(final);
                start = i + 1;
                end = i + 1;
            } else {
                end++;
            }
        }

        if (end == nums.size() - 1) {
            string a = to_string(nums[start]);
            string b = to_string(nums[end]);
            string final = start != end ? a + '-' + '>' + b : a;
            ans.push_back(final);
        }
        return ans;
    }
};