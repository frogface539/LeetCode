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
    void storePre(TreeNode* root , vector<int>& pre){
        if(root == NULL){
            return;
        }

        pre.push_back(root -> val);
        storePre(root -> left , pre);
        storePre(root -> right , pre);
    }
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

        if(root -> val == 0 && root -> left == NULL && root -> right == NULL){
            return;
        }

        vector<int> ans;
        storePre(root , ans);
        int count = 0;
        TreeNode* curr = root;

        while(count < ans.size()){
            curr->right = (count == 0) ? root : new TreeNode(ans[count]);
            curr->left = nullptr;
            
            curr = curr->right;
            curr->val = ans[count];
            count++;
        }
    }
};