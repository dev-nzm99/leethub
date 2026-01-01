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
    int target;
    bool helperFunc(TreeNode* node, int currSum) {
        bool l, r;
        if (node == NULL)
            return false;
        if (node->left == NULL && node->right == NULL) {
            return currSum == target;
        }
        if (node->left)
            l = helperFunc(node->left, currSum + node->left->val);
        if (node->right)
            r = helperFunc(node->right, currSum + node->right->val);
        return l || r;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        return helperFunc(root, (root) ? root->val : 0);
    }
};