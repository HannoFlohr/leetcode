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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* node;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            node = q.front();
            q.pop();
            if(node->right != nullptr) 
                q.push(node->right);
            if(node->left != nullptr)
                q.push(node->left);
        }

        return node->val;
    }
};
//https://leetcode.com/problems/find-bottom-left-tree-value/

/*
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int qsize, bottomleft = 0;
        TreeNode* node;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            bottomleft = q.front()->val;

            qsize = q.size();
            while(qsize--) {
                node = q.front();
                q.pop();
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr) 
                    q.push(node->right);
            }
        }

        return bottomleft;
    }
};
*/