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
class BSTIterator {
public:
    void solve(vector<int>& inorder, TreeNode* root) {
        if (root) {
            solve(inorder, root->left);
            inorder.push_back(root->val);
            solve(inorder, root->right);
        }
    }

    BSTIterator(TreeNode* root) {
        solve(inorder, root);
        size = inorder.size();
        index = 0;
    }

    int next() {
        return inorder[index++];
    }

    bool hasNext() {
        return index < size;
    }

private:
    vector<int> inorder;
    int index;
    int size;
};