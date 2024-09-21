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
    bool solve(TreeNode* root , long long int lowerbound , long long int upperbound){
        if(root == NULL){
            return true;
        }

        bool condition1 = root-> val > lowerbound;
        bool condition2 = root -> val < upperbound;
        bool leftAns = solve(root -> left , lowerbound , root -> val);
        bool rightAns = solve(root -> right , root -> val , upperbound);

        return leftAns && rightAns && condition1 && condition2;
    }

    bool isValidBST(TreeNode* root) {
        long long int lowerbound = LONG_MIN;
        long long int upperbound = LONG_MAX;

        return solve(root , lowerbound , upperbound);
    }
};