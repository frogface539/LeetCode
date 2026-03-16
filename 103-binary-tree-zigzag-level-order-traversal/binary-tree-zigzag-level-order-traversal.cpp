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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>output;
        if(root == NULL){
            return output;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;

        while(!q.empty()){
            int size = q.size();
            vector<int>ans(size);

            for(int i=0 ; i<size ; i++){
                TreeNode* front = q.front();
                q.pop();

                int index;
                if(flag){
                    index = i;
                }
                else{
                    index = size-i-1;
                }
                ans[index] = front->val;

                if(front -> left){
                    q.push(front->left);
                }
                if(front -> right){
                    q.push(front->right);
                }
            }
            flag = !flag;
            output.push_back(ans);
        }
        return output;
    }
};