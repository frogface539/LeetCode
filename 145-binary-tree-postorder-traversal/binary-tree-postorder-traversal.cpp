/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        solve(node->left, result);
        solve(node->right, result);
        result.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
};
