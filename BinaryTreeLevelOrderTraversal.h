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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> lot;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        int size;

        while(!q.empty()) {
            size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++) {
                node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lot.push_back(level);
        }
        
        return lot;
    }
};
//https://leetcode.com/problems/binary-tree-level-order-traversal/

/* above: solution using bfs and queue (faster and less memory)
below: recursive approach

class Solution {
private:
    vector<vector<int>> lot;
public:
    vector<vector<int>> levelOrder(TreeNode* root, int level=0) {
        if(!root) return lot; 
        
        if(level == lot.size()) lot.emplace_back(vector<int>());
        
        lot[level].push_back(root->val);
        
        if(root->left)  levelOrder(root->left, level+1);
        if(root->right) levelOrder(root->right, level+1);
        
        return lot;
    }
};

*/