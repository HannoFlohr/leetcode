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
    int d, good_leaf_pairs = 0;
    
    vector<int> dfs(TreeNode* root) {
        vector<int> result (d+1, 0);
        
        if(!root) return result;
        
        if(!root->left && !root->right) {
            result[1]++;
            return result;
        }
        
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        
        for(int l=1; l<left.size(); l++) 
            for(int r=d-1; r>=0; r--) {
                if(l + r <= d)
                    good_leaf_pairs += left[l] * right[r];
            }
        
        for(int i=result.size()-2; i>=1; i--)
            result[i+1] = left[i] + right[i];
        
        return result;
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        d = distance;
        dfs(root);
        return good_leaf_pairs;
    }
};
//https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/