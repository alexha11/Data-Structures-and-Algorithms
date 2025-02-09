class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int width = right - left;
            int current_area = min(height[left], height[right]) * width;
            maxArea = max(current_area, maxArea);       
            if (height[left] < height[right])
                left += 1;
            else
                right -= 1;
        }
        return maxArea;
    } 
};