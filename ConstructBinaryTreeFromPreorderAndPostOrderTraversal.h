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
private:
    int preorderIndex = 0, postorderIndex = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preorderIndex]);
        preorderIndex++;

        if(root->val != postorder[postorderIndex]) {
            root->left = constructFromPrePost(preorder, postorder);
        }
        if(root->val != postorder[postorderIndex]) {
            root->right = constructFromPrePost(preorder, postorder);
        }

        postorderIndex++;
        return root;
    }
};
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/