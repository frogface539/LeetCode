class Solution {
public:
    void solve(TreeNode* root, TreeNode*& prev) {
        if(root == NULL) {
            return;
        }
        solve(root->left, prev);

        root->left = NULL;
        prev->right = root;
        prev = root;

        solve(root->right, prev);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* prev = dummy;

        solve(root, prev);
        return dummy->right;
    }
};