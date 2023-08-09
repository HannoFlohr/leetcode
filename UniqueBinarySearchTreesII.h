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
    vector<TreeNode*> generateTrees(int start, int end) {
        if(end - start < 0) 
            return {NULL};
        if(end - start == 0) 
            return {new TreeNode(start)};
        
        vector<TreeNode*> bsts, left_trees, right_trees;
        TreeNode* node;
            
        for(int i = start; i <= end; ++i) {
            left_trees = generateTrees(start, i-1);
            right_trees = generateTrees(i+1, end);
                
            for(const auto& left : left_trees)
                for(const auto& right : right_trees) {
                    node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                        
                    bsts.push_back(node);
                }
        }
        
        return bsts;
    }

    //possible improvement, memorize start-end pairs and dont compute multiple times (mainly for larger n)
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};
//https://leetcode.com/problems/unique-binary-search-trees-ii/