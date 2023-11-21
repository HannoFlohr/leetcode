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
    void addValues(TreeNode* node, vector<int>& values) {
        if(node == nullptr)
            return;
        values.push_back(node->val);
        addValues(node->left, values);
        addValues(node->right, values);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> values;
        addValues(root1, values);
        addValues(root2, values);
        sort(values.begin(), values.end());
        return values;
    }
};
//https://leetcode.com/problems/all-elements-in-two-binary-search-trees/