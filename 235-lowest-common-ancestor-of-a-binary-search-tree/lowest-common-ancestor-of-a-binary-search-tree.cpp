/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        TreeNode* leftAns = lowestCommonAncestor(root->left , p , q);
        TreeNode* rightAns = lowestCommonAncestor(root->right , p , q);

        if(p->val > root -> val && q->val > root->val){
            return rightAns;
        }

        if(p -> val < root->val && q->val <root->val){
            return leftAns;
        }

        if(p -> val < root->val && q->val > root->val){
            return root;
        }

        if(p->val > root->val && q->val < root->val){
            return root;
        }
        return root;
    }
};