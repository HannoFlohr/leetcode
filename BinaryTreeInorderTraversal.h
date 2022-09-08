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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        stack<TreeNode*> s;
        
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            
            inOrder.push_back(root->val);
            root = root->right;
        }
        
        return inOrder;
    }
};
//https://leetcode.com/problems/binary-tree-inorder-traversal/

/* recursively:

class Solution {
void inorderTraversal(TreeNode* root, vector<int>& inOrder) {
    if(root == NULL) return;
    
    if(root->left != NULL)
        inorderTraversal(root->left, inOrder);
        
    inOrder.push_back(root->val);
        
    if(root->right)
        inorderTraversal(root->right, inOrder);
}
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        inorderTraversal(root, inOrder);
        return inOrder;
    }
};*