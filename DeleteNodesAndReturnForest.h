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
    TreeNode* deleteNodes(TreeNode* node, bool is_root, vector<int>& to_delete, vector<TreeNode*>& forest) {
        if(node == nullptr) {
            return nullptr;
        }

        bool deleted = find(to_delete.begin(), to_delete.end(), node->val) != to_delete.end();
        if(is_root && !deleted) {
            forest.push_back(node);
        }
        node->left = deleteNodes(node->left, deleted, to_delete, forest);
        node->right = deleteNodes(node->right, deleted, to_delete, forest);
    
        return deleted ? nullptr : node;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        deleteNodes(root, true, to_delete, forest);
        return forest;
    }
};
//https://leetcode.com/problems/delete-nodes-and-return-forest/