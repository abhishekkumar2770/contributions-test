class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Path passing through this node
        diameter = max(diameter, leftHeight + rightHeight);

        // Height of this subtree
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};