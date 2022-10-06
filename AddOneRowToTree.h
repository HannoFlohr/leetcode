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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            newNode->right = NULL;
            return newNode;
        }
        
        if(depth > 2) {
            if(root->left) addOneRow(root->left, val, depth-1);
            if(root->right) addOneRow(root->right, val, depth-1);
            return root;
        }
        
        TreeNode* newleft = new TreeNode(val);
        TreeNode* newright = new TreeNode(val);
        TreeNode* node;
            
        node = root->left;
        root->left = newleft;
        newleft->left = node;
            
        node = root->right;
        root->right = newright;
        newright->right = node;
        return root;
    }
};
//https://leetcode.com/problems/add-one-row-to-tree/