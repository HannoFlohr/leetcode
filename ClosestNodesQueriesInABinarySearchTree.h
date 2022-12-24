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
    void inorder(TreeNode* root, vector<int>& node_values) {
        if(root == nullptr) return;
        inorder(root->left, node_values);
        node_values.push_back(root->val);
        inorder(root->right, node_values);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> result;
        vector<int> node_values;
        inorder(root, node_values);
        
        int min_val, max_val;
        for(auto &q : queries) {
            min_val = -1, max_val = -1;

            //find min/max using lower/upper bounds for q
            if(node_values[0] <= q) 
                min_val = lower_bound(begin(node_values), end(node_values), q) - node_values.begin();
            if(q <= node_values.back())
                max_val = upper_bound(begin(node_values), end(node_values), q) - node_values.begin();
            
            //if q is greater than the last element
            if(min_val > 0 && min_val >= node_values.size()) min_val--;
            //if q is not in the tree, decrement min
            if(min_val >= 0 && node_values[min_val] > q) min_val--;
            //if q present in tree, correct the upper bound
            if(max_val > 0 && node_values[max_val-1] == q) max_val--;

            if(min_val != -1) min_val = node_values[min_val];
            if(max_val != -1) max_val = node_values[max_val];
            result.push_back({min_val, max_val});
        }
        
        return result;
    }
};
//https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/