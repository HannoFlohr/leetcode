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
    vector<TreeNode*> allPossibleFBT(int n) {
        //check if number of nodes is odd
        if((n&1) == 0)
            return {}; 
        if(n == 1)
            return {new TreeNode()};
		
        vector<TreeNode*> FullBinaryTrees;
		
        for(int i = 1; i < n-1; i += 2){  
            vector<TreeNode*> left_children = allPossibleFBT(i);
            vector<TreeNode*> right_children = allPossibleFBT(n-i-1);  
			
            for(const auto& left : left_children){
                for(const auto& right : right_children){
                    TreeNode* root = new TreeNode(); 
                    root->left = left; 
                    root->right = right; 
                    FullBinaryTrees.push_back(root);
                }
            }
        }
		
        return FullBinaryTrees;
    }
};
//https://leetcode.com/problems/all-possible-full-binary-trees/