class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        cout << m << ' ' << n << endl;

        int index = 0;
        int count = 0;
        int l = 0, r = n - 1, t = 0, b = m - 1;

        while (index < m * n) {
            for (int i = l; i <= r && index < m * n ; i++) {
                ans.push_back(matrix[t][i]);
                cout << matrix[t][i] << ' ';
                index++;
            }
            for (int i = t + 1; i < b && index < m * n ; i++) {
                ans.push_back(matrix[i][r]);
                cout << matrix[i][r] << ' ';
                index++;
            }
            for (int i = r; i >= l && index < m * n ; i--) {
                ans.push_back(matrix[b][i]);
                cout << matrix[b][i] << ' ';
                index++;
            }
            for (int i = b - 1; i > t && index < m * n ; i--) {
                ans.push_back(matrix[i][l]);
                cout << matrix[i][l] << ' ';
                index++;
            }
            l++, r--, b--, t++;
        }

        return ans;
    }
    };