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
    TreeNode* replaceValueInTree(TreeNode* root) {
        deque<pair<TreeNode*,int>> q;
        root->val=0;
        q.push_back({root,-1});

        while(!q.empty()){
            int size=q.size();
            int tsum=0;
        for(int i=0;i<size;i++){
            int cval=q[i].first->val,sibval=q[i].second;
            tsum+=cval;
        }
        for(int i=0;i<size;i++){
            int cval=q[i].first->val,sibval=q[i].second;
           q[i].first->val=max(0,tsum-cval-(sibval==-1?0:sibval));
        }
         for(int i=0;i<size;i++){
            auto p=q.front();
            auto cnode=p.first;
            q.pop_front();
            if(cnode->left)q.push_back({cnode->left,(cnode->right?cnode->right->val:-1)});
            if(cnode->right)q.push_back({cnode->right,(cnode->left?cnode->left->val:-1)});
        }

        }
        return root;

    }
};