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
    TreeNode* prev = 0;
    TreeNode* FV = 0;
    TreeNode* SV = 0;
    void solve(TreeNode* curr){
        if(curr == NULL){
            return;
        }

        solve(curr -> left);
        
        if(prev != NULL && curr -> val < prev -> val){
            
            if(FV == NULL){
                FV = prev;
            }
            SV = curr;
        }
        prev = curr;
        solve(curr -> right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        if(FV != NULL && SV != NULL){
            swap(FV -> val , SV->val);
        }
    }
};