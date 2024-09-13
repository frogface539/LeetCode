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
    void solve(TreeNode* root, int targetSum , vector<vector<int>>& ans , vector<int>& temp , int sum){
        if(root == NULL){
            return;
        }

        sum = sum + root -> val;
        temp.push_back(root -> val);

        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == sum) {
                ans.push_back(temp);
            }
        } 
        else {

            solve(root->left, targetSum, ans, temp, sum);
            solve(root->right, targetSum, ans, temp, sum);
        }

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int>temp;
        vector<vector<int>>ans;
        solve(root , targetSum , ans , temp , sum);
        return ans;
    }
};