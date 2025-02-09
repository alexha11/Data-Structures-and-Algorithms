class Solution {
public:
    int checkHeight(TreeNode* node, bool& isBalanced) {
        if (!node) return 0;

        int leftHeight = checkHeight(node->left, isBalanced);
        int rightHeight = checkHeight(node->right, isBalanced);

        if (abs(leftHeight - rightHeight) > 1) {
            isBalanced = false;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        checkHeight(root, isBalanced);
        return isBalanced;
    }
};
