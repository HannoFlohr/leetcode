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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> result;
        
        deque<TreeNode*> q;
        TreeNode* node;
        int level = 0, qsize;
        q.push_back(root);
        
        while(!q.empty()) {
            result.emplace_back(vector<int>());
            
            qsize = q.size();
            
            if(level % 2 == 0) { //even level
                for(int i=0; i<qsize; i++) {
                    node = q.front();
                    q.pop_front();
                    
                    result[level].push_back(node->val);
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                }
            }
            else { //odd level
                for(int i=0; i<qsize; i++) {
                    node = q.back();
                    q.pop_back();
                    
                    result[level].push_back(node->val);
                    if(node->right) q.push_front(node->right);
                    if(node->left) q.push_front(node->left);
                }
            }

            level++;
        }
        
        return result;
    }
};
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/