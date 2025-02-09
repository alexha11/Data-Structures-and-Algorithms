class Solution {
public:
    void dfs(TreeNode* root, int& temp, int cur) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            temp = min(temp, cur);
            return;
        }
        
        dfs(root->left, temp, cur + 1);
        dfs(root->right, temp, cur + 1);
    }
    
    int minDepth(TreeNode* root) {
        int temp = INT_MAX;
        if (root) {
            dfs(root, temp, 1); 
        }
        return temp == INT_MAX ? 0 : temp;  
    }
};
