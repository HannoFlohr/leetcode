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
    void averageOfSubtree(TreeNode* node, int& subtree_sum, int& subtree_nodes, int& count) {
        if(node == nullptr) {
            return;
        }

        int left_sum = 0, left_nodes = 0, right_sum = 0, right_nodes = 0;
        averageOfSubtree(node->left, left_sum, left_nodes, count);
        averageOfSubtree(node->right, right_sum, right_nodes, count);

        subtree_sum += node->val + left_sum + right_sum;
        subtree_nodes += 1 + left_nodes + right_nodes; 
        
        if(node->val == subtree_sum / subtree_nodes) {
            count++;
        }
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0, sum = 0, nodes = 0;
        averageOfSubtree(root, sum, nodes, count);
        return count;
    }
};
//https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/