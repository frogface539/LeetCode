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
    void sortedArray(TreeNode* root, vector<int>&v)
    {
        if(root == NULL)
        {
            return; 
        }
        
        sortedArray(root -> left, v); 
        v.push_back(root -> val); 
        sortedArray(root -> right, v); 
        
    }


    int getMinimumDifference(TreeNode* root) {
        vector<int> v; 
        sortedArray(root, v); 
        int mi = INT_MAX; 
        for(int i = 0; i < v.size() - 1; i ++)
        {
            mi = min(mi, v[i+1] - v[i]); 
        }

        return mi; 
    }
};