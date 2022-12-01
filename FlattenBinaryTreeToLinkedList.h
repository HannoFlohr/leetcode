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
    void flatten(TreeNode* root) {
        TreeNode* node;
        while(root) {
            if(root->left && root->right) {
                //find rightmost leaf to the left of the root and set its right child to the right child of root
                node = root->left;
                while(node->right)
                    node = node->right;
                node->right = root->right;
            }
            
            //left child is next element in list
            if(root->left)
                root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
};
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/