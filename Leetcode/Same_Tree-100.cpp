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
    void dfs (TreeNode* root, vector<int>& f) {
        if (root == nullptr) {
            f.push_back(-9999);
            return;
        }
        f.push_back(root -> val);
        dfs (root -> left, f);
        dfs (root -> right, f);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> f1;
        vector<int> f2;
        dfs(p, f1);
        dfs(q, f2);
        if (f1.size() != f2.size()) return false;
        for (int i = 0; i < f1.size(); i++) {
            if (f1[i] != f2[i]) return false;
        }
        return true;
    }
};