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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        
        return ((root->val >= low && root->val <= high) ? root->val : 0) + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
};
//https://leetcode.com/problems/range-sum-of-bst/

/*

class Solution {
private:
    int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return sum;
        
        if(root->val >= low && root->val <= high)
            sum += root->val;
        
        rangeSumBST(root->left, low, high);
        rangeSumBST(root->right, low, high);
        
        return sum;
    }
};

*/