class Solution {
public:
    unordered_map<int, TreeNode*> mp;

    bool merge(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        if(root->left == NULL && root->right == NULL){
            if(mp.find(root->val) != mp.end()){
                TreeNode* temp = mp[root->val];

                root->left = temp->left;
                root->right = temp->right;

                mp.erase(root->val);
            }
        }

        return merge(root->left) && merge(root->right);
    }

    void inOrder(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return;
        }

        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {

        for(TreeNode* root : trees){
            mp[root->val] = root;
        }

        unordered_set<int> leaves;

        for(TreeNode* root : trees){
            if(root->left)
                leaves.insert(root->left->val);

            if(root->right)
                leaves.insert(root->right->val);
        }

        TreeNode* root = NULL;

        for(TreeNode* node : trees){
            if(leaves.find(node->val) == leaves.end()){
                root = node;
                break;
            }
        }

        if(root == NULL){
            return NULL;
        }

        mp.erase(root->val);

        merge(root);

        if(!mp.empty()){
            return NULL;
        }

        vector<int> arr;
        inOrder(root, arr);

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] <= arr[i-1]){
                return NULL;
            }
        }

        return root;
    }
};