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
    void Solve(TreeNode* root , vector<int>& result){
        if(root == NULL){
            return;
        }

        result.push_back(root -> val);
        Solve(root -> left , result);
        Solve(root -> right , result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        Solve(root , traversal);
        return traversal;
    }
};