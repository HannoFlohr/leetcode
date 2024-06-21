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
    void smallestFromLeaf(TreeNode* node, string s, string& smallest) {
        if(node == nullptr) {
            return;
        }

        s = char(node->val + 'a') + s; 

        if(node->left == nullptr && node->right == nullptr) {
            smallest = min(smallest, s);
            return;
        }

        smallestFromLeaf(node->left, s, smallest);
        smallestFromLeaf(node->right, s, smallest);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string smallest = string(14, 'z');
        smallestFromLeaf(root, "", smallest);
        return smallest;
    }
};
//https://leetcode.com/problems/smallest-string-starting-from-leaf/