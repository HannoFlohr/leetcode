/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> is_child_of; //first is child of second

    void setChildren(TreeNode* root) {
        if(root == nullptr)
            return;

        if(root->left != nullptr) {
            is_child_of[root->left] = root; 
            setChildren(root->left);
        }
        if(root->right != nullptr) {
            is_child_of[root->right] = root; 
            setChildren(root->right);
        }
    }

    void dfs(TreeNode* node, int k, vector<bool>& visited, vector<int>& result) {
        if(visited[node->val] == true)
            return;

        visited[node->val] = true;

        if(k == 0) {
            result.push_back(node->val);
            return;
        }

        if(node->left != nullptr)
            dfs(node->left, k-1, visited, result);
        if(node->right != nullptr)
            dfs(node->right, k-1, visited, result);

        TreeNode* parent = is_child_of[node];
        if(parent != nullptr)
            dfs(parent, k-1, visited, result);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        setChildren(root);

        vector<int> result;
        vector<bool> visited (501, false);
        dfs(target, k, visited, result);

        return result;
    }
};
//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/