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
    bool isSymmetric(TreeNode* n1, TreeNode* n2) {
        if(!n1 && !n2) return true;
        if(!n1 || !n2) return false;
        if(n1->val != n2->val) return false;
        return isSymmetric(n1->left, n2->right) && isSymmetric(n1->right, n2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }
};
//https://leetcode.com/problems/symmetric-tree/

/* iterative solution using two queues

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *left, *right;
        
        queue<TreeNode*> qleft, qright;
        qleft.push(root->left);
        qright.push(root->right);
        while(!qleft.empty() && !qright.empty()) {
            left = qleft.front(); 
            qleft.pop();
            right = qright.front();
            qright.pop();
            
            if(!left && !right)
                continue;
            if(!left || !right)
                return false;
            if(left->val != right->val)
                return false;
            
            qleft.push(left->left);
            qleft.push(left->right);
            qright.push(right->right);
            qright.push(right->left);            
        }
        
        return true;
    }
};

*/