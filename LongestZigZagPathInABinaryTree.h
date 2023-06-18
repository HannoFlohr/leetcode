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
    void longestZigZag(TreeNode* root, bool go_left, int cur_path_length, int& max_path_length) {
        if(root == nullptr) 
            return;

        max_path_length = max(max_path_length, cur_path_length);

        if(go_left) {
            longestZigZag(root->left, false, cur_path_length+1, max_path_length);
            longestZigZag(root->right, true, 1, max_path_length);
        }
        else {
            longestZigZag(root->left, false, 1, max_path_length);
            longestZigZag(root->right, true, cur_path_length+1, max_path_length);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int max_path_length = 0; 
        longestZigZag(root, false, 0, max_path_length);
        longestZigZag(root, true, 0, max_path_length);
        return max_path_length;
    }
};
//https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/