class Solution {
public:
    void inOrder(TreeNode* root, vector<TreeNode*>& trav){
        if(root == NULL){
            return;
        }

        inOrder(root->left, trav);
        trav.push_back(root);
        inOrder(root->right, trav);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> trav;
        inOrder(root, trav);

        TreeNode* first = NULL;
        TreeNode* second = NULL;

        for(int i = 1; i < trav.size(); i++){
            if(trav[i]->val < trav[i-1]->val){
                if(first == NULL){
                    first = trav[i-1];
                }
                second = trav[i];
            }
        }

        swap(first->val, second->val);
    }
};