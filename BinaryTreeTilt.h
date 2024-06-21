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
    int findTilt(TreeNode* node, int& tilt_sum) {
        if(node == nullptr) {
            return 0;
        }
        int left_sum = findTilt(node->left, tilt_sum);
        int right_sum = findTilt(node->right, tilt_sum);
        tilt_sum += abs(left_sum - right_sum);
        return node->val + left_sum + right_sum;
    }
public:
    int findTilt(TreeNode* root) {
        int tilt_sum = 0;
        findTilt(root, tilt_sum);
        return tilt_sum; 
    }
};
//https://leetcode.com/problems/binary-tree-tilt/