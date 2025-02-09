class Solution {
private:
    vector<vector<int>> ans;

    void backtracking(vector<int>& candidates, int target, int curTarget, vector<int>& f, int start) {
        if (curTarget == target) { 
            ans.push_back(f);
            return;
        }
        // for (int i = 0; i < f.size(); i++) cout << f[i] << " ";
        // cout << endl;
         
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            if (curTarget + candidates[i] > target) break;

            f.push_back(candidates[i]); 
            backtracking(candidates, target, curTarget + candidates[i], f, i + 1);
            f.pop_back(); 
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> f;
        ans.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, f, 0);
        return ans;
    }
};
