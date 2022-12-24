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
    void countGoodNodes(TreeNode* root, int max_value, int& good_nodes) {
        if(root == nullptr) return;
        if(root->val >= max_value) good_nodes++; 
        if(root->val > max_value) max_value = root->val;
        countGoodNodes(root->left, max_value, good_nodes);
        countGoodNodes(root->right, max_value, good_nodes);
    }

public:
    int goodNodes(TreeNode* root) {
        int good_nodes = 0;
        countGoodNodes(root, INT_MIN, good_nodes);
        return good_nodes;
    }
};
//https://leetcode.com/problems/count-good-nodes-in-binary-tree/