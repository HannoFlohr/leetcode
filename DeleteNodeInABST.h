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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(key < root->val) //keep searching to the left
            root->left = deleteNode(root->left, key);
        else if(key > root->val) //keep searching to the right
            root->right = deleteNode(root->right, key);
        else { //node to delete found
            if(!root->left && !root->right) //no children
                return NULL;
            if(!root->left || !root->right) //one child
                return root->left ? root->left : root->right;
            
            //find rightmost node of the left subtree and set as new root
            TreeNode* node = root->left;
            while(node->right) node = node->right;
            root->val = node->val;
            root->left = deleteNode(root->left, node->val);
        }
        
        return root;
    }
};
//https://leetcode.com/problems/delete-node-in-a-bst/