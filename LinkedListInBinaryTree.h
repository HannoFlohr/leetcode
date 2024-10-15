/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isCorrectPath(TreeNode* node, const vector<int>& path, int index) {
        if(index == path.size()) 
            return true;
        if(node == nullptr || node->val != path[index])
            return false;
        return isCorrectPath(node->left, path, index+1) || isCorrectPath(node->right, path, index+1);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> path;
        while(head != nullptr) {
            path.push_back(head->val);
            head = head->next;
        }

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while(!q.empty()) {
            node = q.front();
            q.pop();

            if(node->val == path[0] && isCorrectPath(node, path, 0)) {
                return true;
            }

            if(node->left != nullptr)
                q.push(node->left);
            if(node->right != nullptr)
                q.push(node->right);
        }

        return false;
    }
};
//https://leetcode.com/problems/linked-list-in-binary-tree/