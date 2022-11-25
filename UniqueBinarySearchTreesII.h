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
        vector<TreeNode*> results;
        
        if(end - start < 0) 
            results.push_back(NULL);
        else if(end - start == 0) 
            results.push_back(new TreeNode(start));
        else {
            vector<TreeNode*> left, right;
            TreeNode* node;
            
            for(int i=start; i<=end; i++) {
                left = generateTrees(start, i-1);
                right = generateTrees(i+1, end);
                
                for(int j=0; j<left.size(); j++)
                    for(int k=0; k<right.size(); k++) {
                        node = new TreeNode(i);
                        node->left = left[j];
                        node->right = right[k];
                        
                        results.push_back(node);
                    }
            }
        }
        
        return results;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};
//https://leetcode.com/problems/unique-binary-search-trees-ii/