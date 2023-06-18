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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<pair<TreeNode*, int>> q; //<Node,position in tree>
        q.push({root, 0});
        int qsize, start, max_width = 1;
        const int INT_MAX_HALF = INT_MAX/2;

        while(!q.empty()) {
            qsize = q.size();
            start = q.front().second;
            
            max_width = max(max_width, q.back().second - start + 1);

            while(qsize--) {
                auto [node,position] = q.front();
                q.pop();

                auto new_position = position - start;

                if(node->left != nullptr)
                    q.push({node->left, (new_position > INT_MAX_HALF ? (long)2 : 2) * new_position});
                if(node->right != nullptr)
                    q.push({node->right, (new_position > INT_MAX_HALF ? (long)2 : 2) * new_position + 1});
            }
        }

        return max_width;
    }
};
//https://leetcode.com/problems/maximum-width-of-binary-tree/