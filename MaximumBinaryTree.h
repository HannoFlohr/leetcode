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
    TreeNode* construct(vector<int>& nums, int left, int right) { 
        if(left > right) return NULL;

        if(left == right) return new TreeNode(nums[left]);
    
        int max_index = left;
        for(int i=left; i<=right; i++)
            if(nums[i] > nums[max_index])
                max_index = i;

        TreeNode* node = new TreeNode(nums[max_index]); 
        node->left = construct(nums, left, max_index-1);
        node->right = construct(nums, max_index+1, right);

        return node;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size()-1);
    }
};
//https://leetcode.com/problems/maximum-binary-tree/