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
    void sortInorder(TreeNode* node, vector<TreeNode*>& inorder) {
        if(node == nullptr) {
            return;
        }
        sortInorder(node->left, inorder);
        inorder.push_back(node);
        sortInorder(node->right, inorder);
    } 

    TreeNode* makeBalanced(const vector<TreeNode*>& inorder, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int mid = (right+left) / 2;
        TreeNode* node = inorder[mid];
        node->left = makeBalanced(inorder, left, mid-1);
        node->right = makeBalanced(inorder, mid+1, right);
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inorder;
        sortInorder(root, inorder);
        root = makeBalanced(inorder, 0, inorder.size()-1);
        return root;
    }
};
//https://leetcode.com/problems/balance-a-binary-search-tree/