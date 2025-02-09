class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1, target = n * n;
        vector<vector<int>> matrix(n, vector<int>(n));
         while (num <= target) {
            for (int i = left; i <= right && num <= target; i++) {
                matrix[top][i] = num++;
            }
            top++;

            for (int i = top; i <= bottom && num <= target; i++) {
                matrix[i][right] = num++;
            }
            right--;

            for (int i = right; i >= left && num <= target; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;

            for (int i = bottom; i >= top && num <= target; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }

        return matrix;
    }
};
