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
    bool find(TreeNode* node, int value, string& path) {
        if(node->val == value) {
            return true;
        }
        if(node->left != nullptr && find(node->left, value, path)) {
            path += 'L';
        }
        else if(node->right != nullptr && find(node->right, value, path)) {
            path += 'R';
        }
        return !path.empty();
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start, destination;
        find(root, startValue, start);
        find(root, destValue, destination); 

        while(!start.empty() && !destination.empty() && start.back() == destination.back()) {
            start.pop_back();
            destination.pop_back();
        }

        return string(start.size(), 'U') + string(destination.rbegin(), destination.rend());
    }
};
//https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/