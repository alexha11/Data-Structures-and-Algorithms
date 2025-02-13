class Solution {
public:
    int search(vector<int>& nums, int target) {
        // [4,5,6,7,0,1,2]
        // 0
        // [ 4 1, 2 3]
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] == target) return mid;

            if(nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};