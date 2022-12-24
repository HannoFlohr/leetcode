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
    int findMin(TreeNode* root, int last) {
        if(root == nullptr) return -1;

        if(root->val != last) return root->val; 

        int left = findMin(root->left, last);
        int right = findMin(root->right, last);

        if(left == -1) return right;
        if(right == -1) return left;
        return min(left, right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr) return -1;
        return findMin(root, root->val);
    }
};
//https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/