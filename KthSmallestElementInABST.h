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
    int kthSmallest(TreeNode* root, int &k) {
        if(root) {
            int left = kthSmallest(root->left, k);
            return k==0 ? left : (--k==0 ? root->val : kthSmallest(root->right, k));
        }
        
        return -1;
    }
};
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/

/*
In-Order Traversal and decrease k at each node until k is zero
if k is zero after left tree -> result already found
else decrease k and search the right tree 

-----------------------------------
solution using a set to save the values in the tree

class Solution {
private:
    void makeSet(TreeNode* root, set<int> &values) {
        if(!root) return;
        values.insert(root->val);
        makeSet(root->left, values);
        makeSet(root->right, values);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        set<int> values;
        makeSet(root, values);
        return *next(values.begin(), k-1);
    }
};
*/