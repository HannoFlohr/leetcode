//BFS 100% runtime, 21.34% memory use
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,-1});
        int qsize, depth_x = -1, depth_y = -1, parent_x = -1, parent_y = -1, depth = 0;

        while(!q.empty()) {
            qsize = q.size();

            while(qsize-- > 0) { 
                auto [node, parent] = q.front();
                q.pop();

                if(node->val == x) {
                    parent_x = parent;
                    depth_x = depth;
                }
                else if(node->val == y) {
                    parent_y = parent;
                    depth_y = depth;
                }

                if(node->left != nullptr) {
                    q.push({node->left, node->val});
                }
                if(node->right != nullptr) {
                    q.push({node->right, node->val});
                }
            }

            ++depth;
        }
    
        return depth_x == depth_y && parent_x != parent_y;
    }
};
//https://leetcode.com/problems/cousins-in-binary-tree/

//DFS 52.94% runtime, 90.33% memory use
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
    void dfs(TreeNode* node, int x, int y, int depth, int parent, pair<int,int>& x_values, pair<int,int>& y_values) {
        if(node == nullptr) {
            return;
        }
        if(node->val == x) {
            x_values = {depth, parent};
        }
        else if(node->val == y) {
            y_values = {depth, parent};
        }

        dfs(node->left, x, y, depth+1, node->val, x_values, y_values);
        dfs(node->right, x, y, depth+1, node->val, x_values, y_values);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> x_values, y_values;
        dfs(root, x, y, 0, -1, x_values, y_values);
        return x_values.first == y_values.first && x_values.second != y_values.second;
    }
};