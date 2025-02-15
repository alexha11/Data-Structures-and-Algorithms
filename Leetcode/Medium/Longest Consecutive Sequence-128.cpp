class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sets;

        for (int num : nums) {
            sets.insert(num);
        }
        
        int ans = 0;
        for (int set : sets) {
            if (sets.find(set - 1) != sets.end()) continue;
            
            int count = 1;
            while(sets.find(set + count) != sets.end()) count++;

            ans = max(ans, count);
            
        }

        return ans;
    }
};