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
    int countSwaps(vector<int>& level) {
        int swaps = 0;
        vector<int> sorted = level;
        sort(sorted.begin(), sorted.end());
        map<int,int> m;
        for(int i = 0; i < level.size(); ++i)
            m[level[i]] = i;

        for(int i = 0; i < level.size(); ++i) {
            if(level[i] == sorted[i])
                continue;
            
            level[m[sorted[i]]] = level[i];
            m[level[i]] = m[sorted[i]];
            m[sorted[i]] = i;
            level[i] = sorted[i];
            ++swaps;
        }

        return swaps;
    }

public:
    int minimumOperations(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int qsize = q.size();
            vector<int> level;
            while(qsize-- > 0) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }

            result += countSwaps(level);
        }

        return result;
    }
};
//https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/