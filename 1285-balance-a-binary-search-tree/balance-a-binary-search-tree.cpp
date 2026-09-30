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

    TreeNode* createTree(vector<TreeNode*>& arr, int s, int e){
        if(s > e){
            return NULL;
        }
        int mid = s + (e - s) / 2;

        TreeNode* root = new TreeNode(arr[mid]->val);
        root->left = createTree(arr, s, mid - 1);
        root->right = createTree(arr, mid + 1, e);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> trav;
        inOrder(root, trav);
        return createTree(trav, 0, trav.size() - 1);
    }
};