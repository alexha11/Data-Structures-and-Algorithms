/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int& def, int cur) {
        if (root == nullptr){
            def = max(def, cur);
            return;
        }
        cur += 1;
        dfs(root -> left, def, cur);
        dfs(root -> right, def, cur);
    }
    int maxDepth(TreeNode* root) { 
        int def = 0, cur = 0;
        dfs(root, def, cur);
        return def;
    }
};