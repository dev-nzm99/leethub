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
/*
 Author:Nazmul Islam
 Complexity: O(n) time & space
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        int lvl_cnt = 0;

        while (!q.empty()) {
            int n = q.size();
            vector<int> currLvl(n, 0);
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                (lvl_cnt & 1) ? currLvl[n - i - 1] = node->val
                              : currLvl[i] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++lvl_cnt;
            result.push_back(currLvl);
        }
        return result;
    }
};