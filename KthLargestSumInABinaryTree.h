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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSums;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int qsize = q.size();
            long long sum = 0;
            while(qsize--) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }

            levelSums.push_back(sum);
        }

        if(levelSums.size() < k)
            return -1;

        sort(levelSums.rbegin(), levelSums.rend());
        return levelSums[k-1];
    }
};
//https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/