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

void reverseOddLevels(TreeNode* root, TreeNode* root2, int level=0) {
    if((root->left==NULL && root->right==0) || (root->left==NULL && root->right==0)) return;
        
    if(!(level&1)) {
        int val = root->left->val;
        root->left->val = root2->right->val;
        root2->right->val = val;
    }
        
    reverseOddLevels(root->left, root2->right, level+1);
    reverseOddLevels(root->right, root2->left, level+1);
}

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseOddLevels(root, root, 0);
        return root;
    }
};
//https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/