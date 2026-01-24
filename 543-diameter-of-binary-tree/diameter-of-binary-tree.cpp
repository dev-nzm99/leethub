/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = 1 + height(root->left);
        int rightHeight = 1 + height(root->right);
        return max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int maxDiameter = max(leftDiameter, rightDiameter);
        int currNodeDiameter = height(root->left) + height(root->right);
        return max(maxDiameter, currNodeDiameter);
    }
};