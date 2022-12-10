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
    int traverse(TreeNode* root, int min_value, int max_value) {
        if(!root) return max_value - min_value;

        min_value = min(min_value, root->val);
        max_value = max(max_value, root->val);

        return max( traverse(root->left, min_value, max_value), traverse(root->right, min_value, max_value) );
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return traverse(root, root->val, root->val);
    }
};
//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

/*
class Solution {
public:
    int maxAncestorDiff(TreeNode* root, int min_value=1e5, int max_value=0) {
        return root ? max( maxAncestorDiff(root->left, min(min_value, root->val), max(max_value, root->val)),  
                           maxAncestorDiff(root->right, min(min_value, root->val), max(max_value, root->val)) )
                      : max_value - min_value;
    }
};
*/