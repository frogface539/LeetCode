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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root,1});
        
        long long ans = 0;
        
        while(!q.empty()){
            int size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            
            ans = max(ans , end - start + 1);
            
            for(int i=0;i<size;i++)
            {
                auto front = q.front();
                q.pop();
                
                TreeNode* node = front.first;
                long long index = front.second-start;
                
                if(node->left)
                    q.push({node->left , 2*index});
                
                if(node->right)
                    q.push({node->right , 2*index + 1});
            }
        }
        
        return ans;
    }
};