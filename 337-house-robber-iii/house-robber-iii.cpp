class Solution {
public:
    unordered_map<TreeNode*, int> dp; 

    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0; 
        }

        if (dp.find(root) != dp.end()) {
            return dp[root]; 
        }

        // robbing the root node
        int include = root->val;
        if (root->left) {
            include += solve(root->left->left) + solve(root->left->right); 
        }
        if (root->right) {
            include += solve(root->right->left) + solve(root->right->right); 
        }

        // rob the house next to the root node
        int exclude = solve(root->left) + solve(root->right);

        dp[root] = max(include, exclude);
        return dp[root];
    }

    int rob(TreeNode* root) {
        return solve(root); 
    }
};
