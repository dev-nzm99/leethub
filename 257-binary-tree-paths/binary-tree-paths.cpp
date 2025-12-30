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
 Using DFS tree traversal pattern
 Complexity: O(n) time & space
*/

class Solution {
private:
    void helperFunc(TreeNode* root, string path, vector<string>& result) {
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
            return;
        }
        if (root->left) {
            helperFunc(root->left, path + "->" + to_string(root->left->val),
                       result);
        }
        if (root->right) {
            helperFunc(root->right, path + "->" + to_string(root->right->val),
                       result);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path = to_string(root->val);
        helperFunc(root, path, result);
        return result;
    }
};