class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // target = 9
        // 1 2 3 4 5 6 7 9
        //
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> ans;

        if(nums.size() < 4) return ans;
        // 4 Sum: O(n^3): all passed
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int l = j + 1, r = nums.size() - 1;
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                while (l < r) {
                    if (nums[l] + nums[r] > newTarget) r--;
                    else if (nums[l] + nums[r] < newTarget) l++;
                    else {
                        set.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++; r--;
                    }
                } 
            }
        }

        // 4 Sum: O(n^3 * logn) all passed
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                for (int z = j + 1; z < nums.size() - 1; z++) {
                    long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j] -  (long long)nums[z];
                    int l = z + 1, r = nums.size() - 1;
                    while(l <= r) {
                        int mid = (l + r) / 2;
                        if (nums[mid] > newTarget) r = mid - 1;
                        else if (nums[mid] < newTarget) l = mid + 1;
                        else {
                            set.insert({nums[i], nums[j], nums[z], nums[mid]});
                            break;
                        } 
                    }
                }
            }
        }
        for (auto val : set) {
            ans.push_back(val);
        }
        return ans;
    }
};