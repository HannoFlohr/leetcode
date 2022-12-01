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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& root_index, int left, int right) {
        if(left > right) return NULL;
        
        int root_inorder = left;
        while(inorder[root_inorder] != preorder[root_index]) 
            root_inorder++;
        
        TreeNode* node = new TreeNode(inorder[root_inorder]);
        root_index++;
        node->left = buildTree(preorder, inorder, root_index, left, root_inorder-1);
        node->right = buildTree(preorder, inorder, root_index, root_inorder+1, right);
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root_index = 0; 
        return buildTree(preorder, inorder, root_index, 0, inorder.size()-1);
    }
};
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/