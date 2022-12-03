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
    int diameter(TreeNode* node, int &height) {
        if(!node) return 0;
        
        int left_diameter = diameter(node->left, height);
        int right_diameter = diameter(node->right, height);
        
        height = max(height, left_diameter+right_diameter);
        
        return max(left_diameter, right_diameter) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        diameter(root, result);
        return result;
    }
};
//https://leetcode.com/problems/diameter-of-binary-tree/