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
    int getInOrderIndex(vector<int>& inorder, int target){
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }

    TreeNode* constructTree(vector<int>& postorder,vector<int>& inorder,int& postOrderIndex,int inOrderStart,int inOrderEnd,int size){

        if(postOrderIndex < 0 || inOrderStart > inOrderEnd){
            return NULL;
        }

        int element = postorder[postOrderIndex];
        postOrderIndex--;

        TreeNode* root = new TreeNode(element);

        int elementIndex = getInOrderIndex(inorder, element);

        root->right = constructTree(postorder,inorder,postOrderIndex,elementIndex + 1,inOrderEnd,size);
        root->left = constructTree(postorder,inorder,postOrderIndex,inOrderStart,elementIndex - 1,size);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        int postOrderIndex = size - 1;

        return constructTree(postorder,inorder,postOrderIndex,0,inorder.size() - 1,size);
    }
};