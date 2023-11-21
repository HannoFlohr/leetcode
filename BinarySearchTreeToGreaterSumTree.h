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
    void setValues(TreeNode* node, int& sum_of_bigger_values) {
        if(node->right != nullptr)
            setValues(node->right, sum_of_bigger_values);
        
        sum_of_bigger_values += node->val;
        node->val = sum_of_bigger_values;

        if(node->left != nullptr)
            setValues(node->left, sum_of_bigger_values);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum_of_bigger_values = 0;
        setValues(root, sum_of_bigger_values);
        return root;
    }
};
//https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/