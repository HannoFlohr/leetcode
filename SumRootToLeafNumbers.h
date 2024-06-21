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
    void findRootLeafSum(TreeNode* root, int cur_sum, int& root_leaf_sum) {
        cur_sum = 10 * cur_sum + root->val;
        
        if(!root->left && !root->right) {
            root_leaf_sum += cur_sum;
            return;
        }
        
        if(root->left) { 
            findRootLeafSum(root->left, cur_sum, root_leaf_sum);
        }
        if(root->right) { 
            findRootLeafSum(root->right, cur_sum, root_leaf_sum);
        }
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int root_leaf_sum = 0;
        if(root) {
            findRootLeafSum(root, 0, root_leaf_sum);
        }
        return root_leaf_sum;
    }
};
//https://leetcode.com/problems/sum-root-to-leaf-numbers/