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
    void dfs1(TreeNode* root, vector<int>& f1) {
        if (root == nullptr) {
            f1.push_back(-1);
            return;
        } 
        f1.push_back(root->val);
        dfs1(root->left, f1);    
        dfs1(root->right, f1); 
    }
    void dfs2(TreeNode* root, vector<int>& f2) {
        if (root == nullptr) {
            f2.push_back(-1);
            return;
        } 
        f2.push_back(root->val);
        dfs2(root->right, f2);    
        dfs2(root->left, f2); 
    }
    bool isSymmetric(TreeNode* root) {
        vector<int>f1;
        vector<int>f2;
        dfs1(root, f1);
        dfs2(root, f2);
        for (int i = 0; i < f1.size(); i++) {
            if (f1[i] != f2[i]) return false;
        }
        
        return true;
    }
};