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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max(height(root -> left) , height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        int rightHeight = height(root -> right);
        int leftHeight = height(root -> left);
        
        bool leftAns = isBalanced(root -> left);
        bool rightAns = isBalanced(root -> right);
        if(leftAns && rightAns && (abs(rightHeight - leftHeight) <= 1)){
            return true;
        }
        else{
            return false;
        }
        
    }
};