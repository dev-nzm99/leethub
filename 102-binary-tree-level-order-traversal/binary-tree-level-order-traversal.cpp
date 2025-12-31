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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL) // for handled edge case (root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        int currLvl = 0;
        while (!q.empty()) {
            int len = q.size();
            result.push_back({}); // add empty row(level)

            for (int i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();
                result[currLvl].push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            currLvl++;
        }
        return result;
    }
};