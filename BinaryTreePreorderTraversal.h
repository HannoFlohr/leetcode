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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        
		//using Morris traversal for preorder 
        while(root) {
            if(root->left) {
                TreeNode* previous = root->left;
                while(previous->right && previous->right != root)
                    previous = previous->right;
                
                if(!previous->right) {
                    previous->right = root;
                    nodes.push_back(root->val);
                    root = root->left;
                }
                else {
                    previous->right = NULL;
                    root = root->right;
                }
            }
            else {
                nodes.push_back(root->val);
                root = root->right;
            }
        }
        
        return nodes;
    }
};
//https://leetcode.com/problems/binary-tree-preorder-traversal/