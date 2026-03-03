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
        for(int i=0 ; i<inorder.size() ; i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }

    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int& preOrderIndex, int inOrderStart, int inOrderEnd, int size){
        if(preOrderIndex >= size){
            return NULL;
        }
        if(inOrderStart > inOrderEnd){
            return NULL;
        }

        int element = preorder[preOrderIndex];
        preOrderIndex++;
        TreeNode* root = new TreeNode(element);
        int elementIndex = getInOrderIndex(inorder, element);

        root->left = constructTree(preorder,inorder,preOrderIndex,inOrderStart,elementIndex-1,size);
        root->right = constructTree(preorder,inorder,preOrderIndex,elementIndex+1,inOrderEnd,size);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int size = preorder.size();

        return constructTree(preorder, inorder,preOrderIndex,0,inorder.size() - 1,size);
    }
};