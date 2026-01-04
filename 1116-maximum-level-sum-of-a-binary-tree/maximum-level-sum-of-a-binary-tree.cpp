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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        pair<int, int> max_lvl_sum(INT_MIN, 0);
        // unordered_map<int, int> m;
        int CurrLvl = 0;
        while (!q.empty()) {
            int len = q.size();
            int sum = 0;
            CurrLvl++;
            for (int i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (max_lvl_sum.first < sum)
                max_lvl_sum = make_pair(sum, CurrLvl);
        }
        return max_lvl_sum.second;
    }
};