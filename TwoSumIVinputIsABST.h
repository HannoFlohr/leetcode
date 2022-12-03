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
    bool traverse(TreeNode* root, unordered_set<int>& numbers, int k) {
        if(!root) return false;
        
        if(numbers.find(k - root->val) != numbers.end()) 
            return true;
        
        numbers.insert(root->val);
        return traverse(root->left, numbers, k) || traverse(root->right, numbers, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> numbers;
        return traverse(root, numbers, k);
    }
};
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/