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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);

        //BFS for each level of tree
        while(!q.empty()) {
            int qsize = q.size(), sum = 0;
            vector<TreeNode*> level;
            
            //sum up values of all children and store all nodes of the current level
            while(qsize-- > 0) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node);
                if(node->left != nullptr) {
                    q.push(node->left);
                    sum += node->left->val;
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                    sum += node->right->val;
                }
            }

            //for each node of current level: update the sum for the children of each node
            //and update the values of the children 
            for(TreeNode* node : level) {
                int new_val = sum;
                if(node->left != nullptr)
                    new_val -= node->left->val;
                if(node->right != nullptr)
                    new_val -= node->right->val;
                if(node->left != nullptr)
                    node->left->val = new_val;
                if(node->right != nullptr) 
                    node->right->val = new_val;
            }
        }

        return root;
    }
};
//https://leetcode.com/problems/cousins-in-binary-tree-ii/