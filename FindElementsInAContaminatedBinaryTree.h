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
class FindElements {
private:
    unordered_set<int> values;
    
    void recover(TreeNode* root, int val) {
        if(!root) return;
        
        root->val = val;
        values.emplace(val);
        
        recover(root->left, 2*val+1);
        recover(root->right, 2*val+2);
    }
    
public:
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return values.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
 
 //https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/