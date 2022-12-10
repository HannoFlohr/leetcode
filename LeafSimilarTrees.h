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
    void buildLeafSequence(TreeNode* root, vector<int>& leaves) {
        if(!root->left && !root->right) leaves.push_back(root->val);
        if(root->left) buildLeafSequence(root->left, leaves);
        if(root->right) buildLeafSequence(root->right, leaves);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        buildLeafSequence(root1, leaves1);
        buildLeafSequence(root2, leaves2);
        return leaves1 == leaves2;
    }
};
//https://leetcode.com/problems/leaf-similar-trees/