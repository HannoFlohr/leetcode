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
    bool setValues(TreeNode* node, vector<int>& values, int level) {
        if(node == nullptr) {
            return true;
        }
        if(level%2 == node->val%2) {
            return false;
        }

        if(values.size() == level) {
            values.push_back(0);
        }
        if(values[level] != 0) {
            if(level%2 == 0 && values[level] >= node->val)
                return false;
            else if(level%2 == 1 && values[level] <= node->val)
                return false;
        }        

        values[level] = node->val;

        return setValues(node->left, values, level+1) && setValues(node->right, values, level+1);    
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<int> values;
        return setValues(root, values, 0);
    }
};
//https://leetcode.com/problems/even-odd-tree/

// DFS above, BFS below; BFS better for balanced trees, DFS for sparse, vine-like trees 

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int previous_value, qsize;
        bool is_even_level = true;
        TreeNode* node;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            previous_value = 0;
            qsize = q.size();
            
            while(qsize--) {
                node = q.front();
                q.pop();

                if(is_even_level != node->val%2){
                    return false;
                }
                if(previous_value != 0) {
                    if(is_even_level) {
                        if(previous_value >= node->val) {
                            return false;
                        }
                    }
                    else {
                        if(previous_value <= node->val) {
                            return false;
                        }
                    }
                }

                previous_value = node->val;
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)    
                    q.push(node->right);
            }

            is_even_level = !is_even_level;
        }

        return true;
    }
};