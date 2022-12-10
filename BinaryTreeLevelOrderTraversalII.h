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
    vector<vector<int>> result;
    
    int getDepth(TreeNode* root){
        if(!root) 
            return 0;
        return max(getDepth(root->left), getDepth(root->right))+1;
    }
    
    void levelOrderTraversal(TreeNode* node, int level) {
        if(!node) return;
        
        result[level].push_back(node->val);
        
        levelOrderTraversal(node->left, level-1);
        levelOrderTraversal(node->right, level-1);
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = getDepth(root);
        result = vector<vector<int>>(depth, vector<int> {});
        
        levelOrderTraversal(root, depth-1);
        
        return result;
    }
};
//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

/*

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        
        if(!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        int qsize;
        
        while(!q.empty()) {
            qsize = q.size();
            vector<int> level;
            
            for(int i=0; i<qsize; i++) {
                node = q.front();
                q.pop();
                
                level.insert(level.begin(), node->val);
                
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            
            result.insert(result.begin(), level);
        }
        
        return result;
    }
};

*/