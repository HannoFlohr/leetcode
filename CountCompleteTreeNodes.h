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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        TreeNode *left = root, *right = root;
        int h_left = 0, h_right = 0;
        
        //check height on left side of the current node
        while(left) {
            h_left++;
            left = left->left;
        }
        //check height on right side of the current node
        while(right) {
            h_right++;
            right = right->right;
        }
        
        //if same height, (2^height)-1 nodes in this part of the tree; return 
        if(h_left == h_right)
            return pow(2, h_left) - 1;
        
        //count children
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
//https://leetcode.com/problems/count-complete-tree-nodes/