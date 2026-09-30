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
    void inOrder(TreeNode* root, vector<int>& trav){
        if(root == NULL){
            return;
        }

        inOrder(root->left, trav);
        trav.push_back(root->val);
        inOrder(root->right, trav);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>r1;
        vector<int>r2;
        inOrder(root1,r1);
        inOrder(root2,r2);

        vector<int>ans;
        for(int i=0 ; i<r1.size() ; i++){
            ans.push_back(r1[i]);
        }
        for(int i=0 ; i<r2.size() ; i++){
            ans.push_back(r2[i]);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};