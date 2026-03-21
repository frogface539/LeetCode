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

class Info{
public:
    int maxVal;
    int minVal;
    bool isBST;
    int sum;
};

class Solution {
public:

    Info solve(TreeNode* root, int &maxSum){
        if(root == NULL){
            return {INT_MIN, INT_MAX, true, 0};
        }

        Info left = solve(root->left, maxSum);
        Info right = solve(root->right, maxSum);

        Info curr;

        curr.sum = root->val + left.sum + right.sum;
        curr.maxVal = max(root->val, max(left.maxVal, right.maxVal));
        curr.minVal = min(root->val, min(left.minVal, right.minVal));

        curr.isBST = (root->val > left.maxVal &&
                      root->val < right.minVal &&
                      left.isBST && right.isBST);

        if(curr.isBST){
            maxSum = max(maxSum, curr.sum);
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};