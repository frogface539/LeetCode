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

    int solve(TreeNode *root,int t){

        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            return t == 0 ? root->val : 0;
        }
        return solve(root->left,0) + solve(root->right,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,-1);
    }
};