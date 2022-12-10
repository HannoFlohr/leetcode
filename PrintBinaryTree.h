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
    vector<vector<string>> result;

    int getHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fill(TreeNode* root, const int& row, int left, int right) {
        if(!root) return; 

        int mid = left + (right - left) / 2;
        result[row][mid] += to_string(root->val);
        fill(root->left,  row+1, left,  mid-1);
        fill(root->right, row+1, mid+1, right);
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root); 
        int columns = pow(2, height) - 1; 
        result = vector<vector<string>>(height, vector<string>(columns, ""));

        fill(root, 0, 0, columns-1);

        return result;
    }
};
//https://leetcode.com/problems/print-binary-tree/