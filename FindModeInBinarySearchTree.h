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
    int max_count = INT_MIN;
    int cur_count = 0;
    TreeNode* prev = NULL;
    vector<int> modes;
    
    void inorder(TreeNode* root, bool set_modes) {
        if(!root) return;
        
        inorder(root->left, set_modes);
        
        if(prev && prev->val == root->val) cur_count++;
        else cur_count = 1;
        
        if(!set_modes) max_count = max(max_count, cur_count);
        else if(cur_count == max_count) modes.push_back(root->val);
        
        prev = root;
        
        inorder(root->right, set_modes);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        modes.clear();
        if(!root) return modes;
        
        //inorder traversal to find the max count 
        inorder(root, false);
        
        prev = NULL;
        cur_count = 0;
        
        //inorder traversal to set the modes with max count
        inorder(root, true);
        
        return modes;
    }
};
//https://leetcode.com/problems/find-mode-in-binary-search-tree/