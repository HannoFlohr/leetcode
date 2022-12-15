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
class BSTIterator {
private: 
    stack<TreeNode*> nodes;

    void putOnStack(TreeNode* node) {
        while(node) {
            nodes.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        putOnStack(root);
    }
    
    int next() {
        TreeNode* node = nodes.top();
        nodes.pop();
        putOnStack(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
 //https://leetcode.com/problems/binary-search-tree-iterator/