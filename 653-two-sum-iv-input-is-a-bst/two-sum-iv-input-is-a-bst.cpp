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
    void inorderTraversal(vector<int>& inorder, TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inorderTraversal(inorder, root->left);
        inorder.push_back(root->val);
        inorderTraversal(inorder, root->right);
    }

    bool check(vector<int>& inorder , int target){
        int start = 0;
        int end = inorder.size() - 1;
        while(start < end){
            int sum = inorder[start] + inorder[end];
            if(sum == target){
                return true;
            }

            if(sum < target){
                start++;
            }

            if(sum > target){
                end--;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inorderTraversal(inorder , root);
        return check(inorder , k);
    }
};