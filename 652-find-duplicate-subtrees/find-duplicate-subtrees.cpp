class Solution {
public:

    vector<TreeNode*> ans;
    unordered_map<string,int> subTreeMap;

    string preorder(TreeNode* root){
        if(!root)
            return "N";

        string curr = to_string(root->val);
        string left = preorder(root->left);
        string right = preorder(root->right);

        string serial = curr + "." + left + "." + right;

        if(subTreeMap[serial] == 1)
            ans.push_back(root);

        subTreeMap[serial]++;
        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return ans;
    }
};