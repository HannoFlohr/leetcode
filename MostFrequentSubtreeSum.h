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
    map<int,int> sums; //<sum, freq>
    int maxCount = 0;

    int checkSums(TreeNode* root) {
        if(!root) return 0;
        
        int sum = root->val + checkSums(root->left) + checkSums(root->right);
        maxCount = max(maxCount, ++sums[sum]);
        
        return sum;
    }    
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        checkSums(root);

        vector<int> result;
        for(auto &s : sums)
            if(s.second == maxCount)
                result.push_back(s.first);
        
        return result;
    }
};
//https://leetcode.com/problems/most-frequent-subtree-sum/