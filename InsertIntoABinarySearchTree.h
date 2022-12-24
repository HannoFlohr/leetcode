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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        TreeNode* node = root;

        while(root) {
            if(node->val > val) 
                if(node->left != nullptr) 
                    node = node->left;
                else {
                    node->left = new TreeNode(val);
                    break;
                }
            else {
                if(node->right) 
                    node = node->right;
                else {
                    node->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};
//https://leetcode.com/problems/insert-into-a-binary-search-tree/