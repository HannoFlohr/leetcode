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
    vector<string> stack; 
    vector<string> paths;
    
    string stackToString() {
        if(stack.empty()) return "";
        
        string s = stack[0];
        for(int i=1; i<stack.size(); i++)
            s += "->" + stack[i];
        return s;
    } 
    
    void searchPaths(TreeNode* node) {
        stack.push_back(to_string(node->val));
         
        if(node->left) searchPaths(node->left);
        
        if(!node->left && !node->right) paths.push_back(stackToString());
        
        if(node->right)searchPaths(node->right);
        
        stack.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        searchPaths(root);
        return paths;
    }
};
//https://leetcode.com/problems/binary-tree-paths/