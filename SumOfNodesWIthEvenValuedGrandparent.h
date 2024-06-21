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
    void sumEvenGrandparent(TreeNode* node, bool even_parent, bool even_grandparent, int& sum) {
        if(node == nullptr) {
            return;
        }
        if(even_grandparent) {
            sum += node->val;
        }
        even_grandparent = even_parent;
        even_parent = (node->val % 2 == 0);
        sumEvenGrandparent(node->left, even_parent, even_grandparent, sum);
        sumEvenGrandparent(node->right, even_parent, even_grandparent, sum);
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        sumEvenGrandparent(root, false, false, sum);
        return sum;
    }
};
//https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/