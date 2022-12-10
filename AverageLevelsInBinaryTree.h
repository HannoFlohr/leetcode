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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        int qsize; long sum;
        
        while(!q.empty()) {
            qsize = q.size();
            sum = 0;
            
            for(int i=0; i<qsize; i++) {
                node = q.front();
                q.pop();
                
                sum += node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            result.push_back( (double)sum / qsize );
        }
        
        return result;
    }
};
//https://leetcode.com/problems/average-of-levels-in-binary-tree/