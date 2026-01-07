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
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> left_ST, right_ST;
        left_ST.push(root->left);
        right_ST.push(root->right);

        while (!left_ST.empty() && !right_ST.empty()) {
            TreeNode *leftNode, *rightNode;
            leftNode = left_ST.front();
            rightNode = right_ST.front();
            left_ST.pop();
            right_ST.pop();
            if (leftNode == NULL && rightNode == NULL)
                continue;
            if ((leftNode == NULL || rightNode == NULL) ||
                (leftNode->val != rightNode->val))
                return false;
            left_ST.push(leftNode->left);
            left_ST.push(leftNode->right);
            right_ST.push(rightNode->right);
            right_ST.push(rightNode->left);
        }
        return true;
    }
};