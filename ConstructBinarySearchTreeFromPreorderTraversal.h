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
    TreeNode* bstFromPreorder(vector<int>& preorder, int& index, int parent) {
        if(index == preorder.size() ||  preorder[index] > parent) { 
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[index]);
        ++index;
        node->left = bstFromPreorder(preorder, index, node->val);
        node->right = bstFromPreorder(preorder, index, parent);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bstFromPreorder(preorder, index, 1111);
    }
};
//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/