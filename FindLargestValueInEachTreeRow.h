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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }

        vector<int> largest_per_row;
        queue<TreeNode*> q;
        TreeNode* cur;
        int largest, qsize;

        q.push(root);
        while(!q.empty()) {
            largest = INT_MIN;
            qsize = q.size();

            while(qsize--) {
                cur = q.front();
                q.pop();

                largest = max(largest, cur->val);

                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
            }

            largest_per_row.push_back(largest);
        }

        return largest_per_row;
    }
};
//https://leetcode.com/problems/find-largest-value-in-each-tree-row/