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
    int maxLevelSum(TreeNode* root) {
        int levelSum, maxSum = INT_MIN, levelAtMaxSum = -1, level = 1, levelSize;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while( !q.empty() ) {
            levelSize = q.size();
            levelSum = 0;
            for(int i=0; i<levelSize; i++) {
                node = q.front();
                q.pop();
                levelSum += node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            if(maxSum < levelSum) {
                maxSum = levelSum;
                levelAtMaxSum = level;
            }
            
            level++;
        }
        
        return levelAtMaxSum;
    }
};
//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/