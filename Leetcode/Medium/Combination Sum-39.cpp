class Solution {
private: 
    vector<vector<int>> ans; 

    void backtracking(vector<int>& candidates, int target, int curTarget, vector<int>& f, int start) {
        if (curTarget > target) {
            return;
        }
        
        if (curTarget == target) { 
            ans.push_back(f);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            f.push_back(candidates[i]); 

            backtracking(candidates, target, curTarget + candidates[i], f, i);
            f.pop_back(); 
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> f;
        ans.clear(); 
        backtracking(candidates, target, 0, f, 0);
        return ans;
    }
};
