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
    int distributeCoins(TreeNode* root, TreeNode* parent = nullptr) {
        if(root == nullptr) {
            return 0;
        }

        int moves = distributeCoins(root->left, root) + distributeCoins(root->right, root);
        int value = root->val - 1;
        if(parent != nullptr) {
            parent->val += value;
        }
        moves += abs(value);
        return moves;
    }
};
//https://leetcode.com/problems/distribute-coins-in-binary-tree/