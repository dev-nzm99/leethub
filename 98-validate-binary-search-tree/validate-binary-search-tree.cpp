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
    void helperFunc(vector<int>& arr, TreeNode* root) {
        if (root == NULL)
            return;
        helperFunc(arr, root->left);
        arr.push_back(root->val);
        helperFunc(arr, root->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        vector<int> values;
        helperFunc(values, root);
        return is_sorted(values.begin(), values.end(),
                         [](const int a, const int b) { return a <= b; });
    }
};