class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }

        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inorder;
        inOrder(root, inorder);

        vector<vector<int>> ans;

        for(int q : queries) {
            int low = -1;
            int high = -1;

            int start = 0;
            int end = inorder.size() - 1;

            while(start <= end) {
                int mid = start + (end - start) / 2;

                if(inorder[mid] == q) {
                    low = inorder[mid];
                    high = inorder[mid];
                    break;
                }
                else if(inorder[mid] < q) {
                    low = inorder[mid];
                    start = mid + 1;
                }
                else {
                    high = inorder[mid];
                    end = mid - 1;
                }
            }

            ans.push_back({low, high});
        }

        return ans;
    }
};