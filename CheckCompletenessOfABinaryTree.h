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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        int node = 0;

        //count nodes until first NULL is encountered
        while(node < bfs.size() && bfs[node] != nullptr) {
            bfs.push_back(bfs[node]->left);
            bfs.push_back(bfs[node]->right);
            node++;
        }
        //count nodes after first NULL stopping if a real value is found
        while(node < bfs.size() && bfs[node] == nullptr)
            node++;

        //if counted nodes == size of tree -> it is complete
        return node == bfs.size();
    }
};
//https://leetcode.com/problems/check-completeness-of-a-binary-tree/