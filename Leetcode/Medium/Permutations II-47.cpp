class Solution {
private:
    vector<vector<int>> ans;
    vector<int> f;
    vector<bool> check; 

    void backtracking(vector<int>& nums) {
        if (f.size() == nums.size()) {
            ans.push_back(f);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !check[i - 1]) 
                continue;

            if (!check[i]) { 
                check[i] = true;
                f.push_back(nums[i]);

                backtracking(nums);

                f.pop_back();
                check[i] = false; 
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        f.clear();
        check.assign(nums.size(), false);

        sort(nums.begin(), nums.end());

        backtracking(nums);
        return ans;
    }
};

