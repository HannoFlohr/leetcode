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
    unordered_map<int,int> inorder_index; //map inorder value to inorder index
    
    TreeNode* buildTree(vector<int>& postorder, int io_left, int io_right) {
        if(io_left > io_right) return NULL; 
        
        //last postorder element is cur root node value;
        int root_value = postorder[postorder.size()-1];
        postorder.pop_back();
        TreeNode* node = new TreeNode(root_value);
        
        //inorder index of the root value
        int io_index_root = inorder_index[root_value];
        inorder_index.erase(root_value);
        
        //generate left and right subtrees
        node->right = buildTree(postorder, io_index_root+1, io_right);
        node->left = buildTree(postorder, io_left, io_index_root-1);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++)
            inorder_index[inorder[i]] = i;
        
        return buildTree(postorder, 0, postorder.size()-1);
    }
};
//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/